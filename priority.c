#include <stdio.h>

struct Process {
    int id, bt, priority;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Burst Time and Priority for Process %d: ", p[i].id);
        scanf("%d%d", &p[i].bt, &p[i].priority);
    }

    // Sort by priority
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + p[i - 1].bt;

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + p[i].bt;
        printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].id, p[i].bt, p[i].priority, wt[i], tat[i]);
    }

    return 0;
}
