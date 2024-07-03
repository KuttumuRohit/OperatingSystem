#include <stdio.h>
#include <stdbool.h>

void deadlockDetection(int processes[], int n, int avail[], int alloc[][3], int request[][3]) {
    int work[3];
    bool finish[n];
    int deadlockProcesses[n];
    int deadlockCount = 0;

    for (int i = 0; i < 3; i++) {
        work[i] = avail[i];
    }
    
    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }
    
    while (true) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < 3; j++) {
                    if (request[p][j] > work[j])
                        break;
                }
                if (j == 3) {
                    for (int k = 0; k < 3; k++) {
                        work[k] += alloc[p][k];
                    }
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    printf("Processes involved in deadlock: ");
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            deadlockProcesses[deadlockCount++] = i;
            printf("%d ", i);
        }
    }
    if (deadlockCount == 0) {
        printf("No deadlock detected found in the Procces.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
    int avail[] = {1, 5, 3};
    int alloc[][3] = {{1, 1, 0}, {2, 1, 0}, {3, 0, 3}, {2, 1, 0}, {0, 0, 2}};
    int request[][3] = {{0, 0, 0}, {2, 0, 2}, {1, 0, 0}, {1, 0, 1}, {0, 0, 2}};
    
    deadlockDetection(processes, n, avail, alloc, request);
    return 0;
}
