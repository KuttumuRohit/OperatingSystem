#include <stdio.h>
#include <stdbool.h>

bool isSafe(int processes[], int n, int avail[], int max[][3], int alloc[][3]) {
    int need[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    bool finish[n];
    for (int i = 0; i < n; i++) {
        finish[i] = false;
    }
    int safeSeq[n];
    int work[3];
    for (int i = 0; i < 3; i++) {
        work[i] = avail[i];
    }
    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (finish[p] == false) {
                int j;
                for (j = 0; j < 3; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                if (j == 3) {
                    for (int k = 0; k < 3; k++) {
                        work[k] += alloc[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (found == false) {
            printf("System is not in safe state\n");
            return false;
        }
    }
    printf("System is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
    int avail[] = {3, 3, 2};
    int max[][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int alloc[][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    
    isSafe(processes, n, avail, max, alloc);
    return 0;
}
