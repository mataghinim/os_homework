#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    char path[256];
    int fd;
    off_t size;
    char ch;

    printf("Enter file path: ");
    if (scanf("%255s", path) != 1) {
        fprintf(stderr, "Failed to read path.\n");
        return 1;
    }

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    size = lseek(fd, 0, SEEK_END);
    if (size == (off_t)-1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    // empty file: just print newline
    if (size == 0) {
        write(STDOUT_FILENO, "\n", 1);
        close(fd);
        return 0;
    }

    // read bytes from end to start
    for (off_t pos = size - 1; pos >= 0; pos--) {
        if (lseek(fd, pos, SEEK_SET) == (off_t)-1) {
            perror("lseek");
            close(fd);
            return 1;
        }

        if (read(fd, &ch, 1) != 1) {
            perror("read");
            close(fd);
            return 1;
        }

        if (write(STDOUT_FILENO, &ch, 1) != 1) {
            perror("write");
            close(fd);
            return 1;
        }
    }

    write(STDOUT_FILENO, "\n", 1);

    close(fd);
    return 0;
}
