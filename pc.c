#include <stdio.h>
#include <stdlib.h>

int buffer[100];
int in = 0, out = 0, count = 0;
int size;

void produce(int item) {
    if (count == size) {
        printf("Buffer is FULL\n");
        return;
    }

    buffer[in] = item;
    in = (in + 1) % size;
    count++;

    printf("Item %d stored in buffer\n", item);
}

void consume() {
    if (count == 0) {
        printf("Buffer is EMPTY\n");
        return;
    }

    int item = buffer[out];
    out = (out + 1) % size;
    count--;

    printf("Item %d consumed from buffer\n", item);
}

void display() {
    if (count == 0) {
        printf("Buffer is EMPTY\n");
        return;
    }

    printf("Items in buffer: ");
    
    int i, index = out;
    for (i = 0; i < count; i++) {
        printf("%d ", buffer[index]);
        index = (index + 1) % size;
    }

    printf("\nTotal items: %d\n", count);
}

int main() {
    int choice, item;

    printf("Enter buffer size: ");
    scanf("%d", &size);

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter item to produce: ");
            scanf("%d", &item);
            produce(item);
            break;

        case 2:
            consume();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
