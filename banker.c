#include <stdio.h>
#define P 5
#define R 3

int main() {
    int alloc[P][R] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int max[P][R] =   { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    int avail[R] = {3, 3, 2};

    int finish[P], need[P][R], safeSeq[P];
    for (int i = 0; i < P; i++) {
        finish[i] = 0;
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > avail[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        avail[k] += alloc[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is not in a safe state\n");
            return 0;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");
    return 0;
}
