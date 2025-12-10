#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
    const char *fname = "data.txt";
    const char *text  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t len = 26;

    // create/overwrite and write the alphabet
    int fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open write");
        return 1;
    }
    if (write(fd, text, len) != (ssize_t)len) {
        perror("write"); close(fd); return 1;
    }
    close(fd);

    // reopen read/write and print current size
    fd = open(fname, O_RDWR);
    if (fd < 0) {
        perror("open rdwr"); return 1;
    }
    off_t size = lseek(fd, 0, SEEK_END);
    if (size == (off_t)-1) {
        perror("lseek end");
        close(fd);
        return 1;
    }
    printf("Size before truncate: %lld\n", (long long)size);

    // truncate to 10 bytes
    if (ftruncate(fd, 10) == -1) { perror("ftruncate"); close(fd); return 1; }

    // print new size
    size = lseek(fd, 0, SEEK_END);
    if (size == (off_t)-1) { 
        perror("lseek end");
        close(fd);
        return 1; }
    printf("Size after truncate:  %lld\n", (long long)size);

    // rewind and read remaining content, print to stdout
    if (lseek(fd, 0, SEEK_SET) == (off_t)-1) {
        perror("lseek set");
        close(fd); return 1;
    }
    char *buf = malloc(1024);
    if (!buf) {
        perror("malloc");
        close(fd);
        return 1;
    }

    ssize_t n = read(fd, buf, 1024);
    if (n < 0) { perror("read"); free(buf); close(fd); return 1; }
    write(STDOUT_FILENO, "Content: ", 9);
    write(STDOUT_FILENO, buf, n);
    write(STDOUT_FILENO, "\n", 1);

    free(buf);
    close(fd);
    return 0;
}
