#include <stdio.h>
#include <stdlib.h>

int n, head, req[50];

void sort() {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            if(req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
}

// SSTF
void SSTF() {

    int visited[50] = {0};
    int total = 0, pos = head;
    int i, j, min, index, dist;

    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < n; i++) {

        min = 9999;

        for(j = 0; j < n; j++) {

            if(!visited[j]) {

                dist = abs(pos - req[j]);

                if(dist < min) {
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        total += min;
        pos = req[index];

        printf(" -> %d", pos);
    }

    printf("\nTotal Seek Time = %d\n", total);
}

// LOOK
void LOOK() {

    int i, total = 0, pos = head;

    sort();

    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < n; i++) {

        if(req[i] >= head) {

            for(int j = i; j < n; j++) {
                total += abs(pos - req[j]);
                pos = req[j];
                printf(" -> %d", pos);
            }

            for(int j = i - 1; j >= 0; j--) {
                total += abs(pos - req[j]);
                pos = req[j];
                printf(" -> %d", pos);
            }

            break;
        }
    }

    printf("\nTotal Seek Time = %d\n", total);
}

// C-SCAN
void CSCAN() {

    int i, total = 0, pos = head;
    int disk_size = 200;

    sort();

    printf("\nSeek Sequence: %d", pos);

    for(i = 0; i < n; i++) {

        if(req[i] >= head) {

            for(int j = i; j < n; j++) {
                total += abs(pos - req[j]);
                pos = req[j];
                printf(" -> %d", pos);
            }

            total += abs(pos - (disk_size - 1));
            pos = 0;

            printf(" -> %d", pos);

            for(int j = 0; j < i; j++) {
                total += abs(pos - req[j]);
                pos = req[j];
                printf(" -> %d", pos);
            }

            break;
        }
    }

    printf("\nTotal Seek Time = %d\n", total);
}

int main() {

    int choice, i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    while(1) {

        printf("\n1. SSTF\n2. LOOK\n3. C-SCAN\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                SSTF();
                break;

            case 2:
                LOOK();
                break;

            case 3:
                CSCAN();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}
