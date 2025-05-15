#include <stdio.h>
#define SIZE 3

int main() {
    int pages[20], n, frames[SIZE], i, j = 0, faults = 0;
    for (i = 0; i < SIZE; i++) frames[i] = -1;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page numbers: ");
    for (i = 0; i < n; i++) scanf("%d", &pages[i]);

    for (i = 0; i < n; i++) {
        int found = 0;
        for (int k = 0; k < SIZE; k++)
            if (frames[k] == pages[i]) found = 1;

        if (!found) {
            frames[j] = pages[i];
            j = (j + 1) % SIZE;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
