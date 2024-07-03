#include <stdio.h>

void findPageFaults(int pages[], int n, int capacity) {
    int frame[capacity];
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }
    int index = 0, pageFaults = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % capacity;
            pageFaults++;
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 2};
    int n = sizeof pages / sizeof pages[0];
    int capacity = 3;
    
    findPageFaults(pages, n, capacity);
    return 0;
}
