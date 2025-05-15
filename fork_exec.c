#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();  // Create a child process

    if (pid < 0) {
        // If fork fails
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process running 'ls' command:\n");
        execl("/bin/ls", "ls", NULL);  // Replace child with 'ls'
        perror("execl failed");  // If execl fails
    } else {
        // Parent process
        wait(NULL);  // Wait for child to finish
        printf("Parent process: Child finished.\n");
    }

    return 0;
}
