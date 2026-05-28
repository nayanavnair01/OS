#include <stdio.h>

int main() {

    int pages[50], frames[10];
    int n, f, i, j, k = 0;
    int fault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {

        found = 0;

        // Check page hit
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page fault
        if(found == 0) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }

        // Display frames
        printf("\n");
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", fault);

    return 0;
}
