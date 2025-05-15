#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else {
        // Parent process
        close(fd[0]);
        char message[] = "Hello Child";
        write(fd[1], message, strlen(message) + 1);
    }
    return 0;
}
