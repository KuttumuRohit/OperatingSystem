#include <stdio.h>

int findOptimal(int pages[], int temp[], int n, int index) {
    int i, j, pos = -1, farthest = index;
    for (i = 0; i < n; ++i) {
        int found = 0;
        for (j = index; j < 30; ++j) {
            if (temp[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], flag1, flag2, i, j, pos, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    faults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            pos = findOptimal(pages, frames, no_of_frames, i + 1);
            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1)
                printf("%d\t", frames[j]);
            else
                printf("-\t");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
