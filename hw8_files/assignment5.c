#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
    int fd;
    off_t size;
    const char *start = "START";
    const char *end   = "END";

    //create sparse.bin, truncate if it exists
    fd = open("sparse.bin", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open for write");
        return 1;
    }

    //write "START" at the beginning
    if (write(fd, start, strlen(start)) != (ssize_t)strlen(start)) {
        perror("write START");
        close(fd);
        return 1;
    }

    //skip forward by 1 MiB without writing zeros (create a hole)
    if (lseek(fd, 1024 * 1024, SEEK_CUR) == (off_t)-1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    //write "END" at the far offset
    if (write(fd, end, strlen(end)) != (ssize_t)strlen(end)) {
        perror("write END");
        close(fd);
        return 1;
    }

    /*
       the gap between "START" and "END" is a sparse hole.
       The filesystem does not allocate real disk blocks for this hole,
       so tools like `du` show very small disk usage, even though
       the logical file size (reported by lseek/ls -l) is large.
    */
    close(fd);

    //reopen read-only and print apparent size
    fd = open("sparse.bin", O_RDONLY);
    if (fd < 0) {
        perror("open for read");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    if (size == (off_t)-1) {
        perror("lseek end");
        close(fd);
        return 1;
    }

    printf("Apparent file size: %lld bytes\n", (long long)size);

    close(fd);
    return 0;
}
