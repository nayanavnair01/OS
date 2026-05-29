#include <stdio.h>

int main() {

    int pages[20], frames[10], used[10];
    int n, f, i, j;

    int faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++) {
        frames[i] = -1;
        used[i] = 0;
    }

    for(i = 0; i < n; i++) {

        int found = 0;

        // Check page hit
        for(j = 0; j < f; j++) {

            if(frames[j] == pages[i]) {

                found = 1;

                used[j] = i;

                break;
            }
        }

        // Page fault
        if(found == 0) {

            int min = used[0];
            int pos = 0;

            for(j = 1; j < f; j++) {

                if(used[j] < min) {

                    min = used[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];

            used[pos] = i;

            faults++;
        }

        // Display frames
        printf("\n");

        for(j = 0; j < f; j++) {

            if(frames[j] != -1)
                printf("%d ", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}
