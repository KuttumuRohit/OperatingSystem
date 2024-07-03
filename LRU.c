#include <stdio.h>

int main() {
    int referenceString[10], pageFaults = 0, m, n, s, pages, frames;

    printf("\nEnter the number of Pages:\t");
    scanf("%d", &pages);

    printf("\nEnter reference string values:\n");
    for (m = 0; m < pages; m++) {
        printf("Value No. [%d]:\t", m + 1);
        scanf("%d", &referenceString[m]);
    }

    printf("\nWhat are the total number of frames:\t");
    scanf("%d", &frames);

    int temp[frames], counter[frames], time = 0;

    for (m = 0; m < frames; m++) {
        temp[m] = -1;
        counter[m] = 0;
    }

    for (m = 0; m < pages; m++) {
        s = 0;
        for (n = 0; n < frames; n++) {
            if (referenceString[m] == temp[n]) {
                s++;
                counter[n] = ++time;
                break;
            }
        }
        if (s == 0) {
            int pos = 0, min = counter[0];
            for (n = 1; n < frames; n++) {
                if (counter[n] < min) {
                    min = counter[n];
                    pos = n;
                }
            }
            temp[pos] = referenceString[m];
            counter[pos] = ++time;
            pageFaults++;
        }
        printf("\n");
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf("%d\t", temp[n]);
            else
                printf("-\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);

    return 0;
}
