#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char *src_path = malloc(sizeof(char) * 255);
    char *dest_path = malloc(sizeof(char) * 255);


    if (!src_path || !dest_path) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Enter source file path: ");
    scanf("%s", src_path);
    printf("Enter destination file path: ");
    scanf("%s", dest_path);

    int in = open(src_path, O_RDONLY);
    if (in < 0) {
        perror("open source");
        return 1;
    }

    int out = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        perror("open dest");
        close(in);
        return 1;
    }
    char *buf = malloc(1024);
    if (!buf) {
        perror("malloc");
        close(in);
        close(out);
        return 1;
    }

    ssize_t bytes;
    ssize_t total = 0;

    while ((bytes = read(in, buf, 1024)) > 0) {
        if (write(out, buf, bytes) != bytes) {
            perror("write");
            break;
        }
        total += bytes;
    }

    if (bytes < 0)
        perror("read");

    printf("Total bytes copied: %zd\n", total);

    free(buf);
    close(in);
    close(out);

    return 0;
}