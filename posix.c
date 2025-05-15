#include <stdio.h>
#include <pthread.h>

void* print_msg(void* msg) {
    printf("Message: %s\n", (char*)msg);
    return NULL;
}

int main() {
    pthread_t thread;
    char* message = "Hello from thread";
    pthread_create(&thread, NULL, print_msg, message);
    pthread_join(thread, NULL);
    return 0;
}