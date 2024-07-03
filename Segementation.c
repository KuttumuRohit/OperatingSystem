#include <stdio.h>

#define MAX_SEGMENTS 10

typedef struct {
    int base;
    int limit;
} Segment;

int main() {
    Segment segmentTable[MAX_SEGMENTS];
    int segmentRefs[] = {0, 1, 2, 0, 0, 4, 3, 1, 2, 3};
    int n = sizeof segmentRefs / sizeof segmentRefs[0];
    
    segmentTable[0].base = 0;
    segmentTable[0].limit = 100;
    segmentTable[1].base = 100;
    segmentTable[1].limit = 50;
    segmentTable[2].base = 150;
    segmentTable[2].limit = 200;
    segmentTable[3].base = 350;
    segmentTable[3].limit = 300;
    
    for (int i = 0; i < n; i++) {
        int seg = segmentRefs[i];
        if (seg < 4) {
            printf("Logical Address: Segment %d\n", seg);
            printf("Physical Address: Base %d, Limit %d\n", segmentTable[seg].base, segmentTable[seg].limit);
        } else {
            printf("Segment %d not found\n", seg);
        }
    }
    return 0;
}
