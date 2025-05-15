#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages, i, j, k, pos, faults = 0;
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages];
    printf("Enter page reference string: ");
    for (i = 0; i < pages; ++i)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames], time[frames], counter = 0;
    for (i = 0; i < frames; ++i)
        frame[i] = -1;

    for (i = 0; i < pages; ++i) {
        int found = 0;

        for (j = 0; j < frames; ++j) {
            if (frame[j] == page[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if (!found) {
            for (j = 0; j < frames; ++j) {
                if (frame[j] == -1) {
                    counter++;
                    faults++;
                    frame[j] = page[i];
                    time[j] = counter;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            pos = findLRU(time, frames);
            counter++;
            faults++;
            frame[pos] = page[i];
            time[pos] = counter;
        }

        printf("\nFrames: ");
        for (j = 0; j < frames; ++j)
            printf("%d ", frame[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
