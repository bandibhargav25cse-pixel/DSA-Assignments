/*A service centre uses a fixed-size request buffer in which released positions must be reused. Write a C program to implement a Circular Queue using an array 
with insertion, deletion, display, overflow and underflow operations. Demonstrate that positions freed after deletion can be reused for new requests */
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element
void insertion(int value) {
    // Check for overflow
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    // First element
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted into queue.\n", value);
}

// Delete an element
void deletion() {
    int value;

    // Check for underflow
    if (front == -1) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    value = queue[front];
    printf("%d deleted from queue.\n", value);

    // If only one element is present
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertion(value);
                break;

            case 2:
                deletion();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
