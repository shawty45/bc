#include <stdio.h>

int findOptimal(int page[], int frame[], int index, int pages, int frames) {
    int i, j, farthest = index, pos = -1;
    int found;

    for (i = 0; i < frames; ++i) {
        found = 0;
        for (j = index; j < pages; ++j) {
            if (frame[i] == page[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if (!found)
            return i;
    }

    return (pos == -1) ? 0 : pos;
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

    int frame[frames];
    for (i = 0; i < frames; ++i)
        frame[i] = -1;

    for (i = 0; i < pages; ++i) {
        int found = 0;

        for (j = 0; j < frames; ++j) {
            if (frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (j = 0; j < frames; ++j) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    faults++;
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            pos = findOptimal(page, frame, i + 1, pages, frames);
            frame[pos] = page[i];
            faults++;
        }

        printf("\nFrames: ");
        for (j = 0; j < frames; ++j)
            printf("%d ", frame[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
