#include <stdio.h>

#define MAX 10

void displayPageTable(int pages[], int frames[], int n, int capacity) {
    printf("Page Table:\n");
    for (int i = 0; i < n; i++) {
        if (pages[i] != -1)
            printf("Page %d -> Frame %d\n", i, pages[i]);
    }
    printf("\nFrames:\n");
    for (int i = 0; i < capacity; i++) {
        if (frames[i] != -1)
            printf("Frame %d -> Page %d\n", i, frames[i]);
    }
}

int main() {
    int capacity = 3;
    int frames[3] = {-1, -1, -1};
    int pages[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int pageRefs[] = {7, 0, 1, 0, 0, 3, 1, 4, 0, 3};
    int n = sizeof pageRefs / sizeof pageRefs[0];
    
    for (int i = 0; i < n; i++) {
        int page = pageRefs[i];
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    frames[j] = page;
                    pages[page] = j;
                    break;
                }
            }
        }
    }
    displayPageTable(pages, frames, MAX, capacity);
    return 0;
}
