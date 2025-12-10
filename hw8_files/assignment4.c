#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    int fd;
    char buf[1024];
    ssize_t n;

    // open log.txt in append mode
    fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // read one line from stdin (using read, not fgets/gets)
    n = read(STDIN_FILENO, buf, sizeof(buf) - 1);
    if (n < 0) {
        perror("read");
        close(fd);
        return 1;
    }
    buf[n] = '\0';

    // remove trailing newline if exists
    if (n > 0 && buf[n - 1] == '\n')
        buf[n - 1] = '\0';

    // prepare prefix with PID
    char prefix[64];
    int len = snprintf(prefix, sizeof(prefix), "PID=%d: ", getpid());

    // write prefix
    if (write(fd, prefix, len) != len) {
        perror("write");
        close(fd);
        return 1;
    }

    // write the user line
    if (write(fd, buf, n) < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    // add newline
    if (write(fd, "\n", 1) != 1) {
        perror("write");
        close(fd);
        return 1;
    }

    /*
    Even with O_APPEND, the file offset grows normally.
    The kernel forces all writes to the end of file, but SEEK_CUR
    still moves forward by the number of bytes written.
    */
    off_t pos = lseek(fd, 0, SEEK_CUR);
    printf("Final offset: %lld\n", (long long)pos);

    close(fd);
    return 0;
}
