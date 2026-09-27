/*A department maintains student roll numbers dynamically. Write a C program using a Singly Linked List to create the list, insert at the beginning and end,
search for a specified roll number, delete a specified roll number, and display the updated list after each operation. Handle the case when a 
requested roll number is not available. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int roll) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->roll = roll;
    newNode->next = NULL;

    return newNode;
}

// Insert at beginning
void insertBeginning(int roll) {
    struct Node *newNode = createNode(roll);

    newNode->next = head;
    head = newNode;

    printf("%d inserted at beginning.\n", roll);
}

// Insert at end
void insertEnd(int roll) {
    struct Node *newNode = createNode(roll);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("%d inserted at end.\n", roll);
}

// Search for a roll number
void search(int roll) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d found at position %d.\n",
                   roll, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Roll number %d is not available.\n", roll);
}

// Delete a roll number
void deleteRoll(int roll) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL) {
        printf("List is empty. Roll number %d cannot be deleted.\n", roll);
        return;
    }

    // If first node contains the roll number
    if (head->roll == roll) {
        head = head->next;
        free(temp);

        printf("Roll number %d deleted successfully.\n", roll);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    // Roll number not found
    if (temp == NULL) {
        printf("Roll number %d is not available.\n", roll);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Roll number %d deleted successfully.\n", roll);
}

// Display the list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Student list is empty.\n");
        return;
    }

    printf("Student Roll Numbers: ");

    while (temp != NULL) {
        printf("%d -> ", temp->roll);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, roll, n, i;

    printf("Enter number of students to create: ");
    scanf("%d", &n);

    printf("Enter %d roll numbers:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    printf("\nInitial List:\n");
    display();

    while (1) {
        printf("\n--- Student Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                display();
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                display();
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteRoll(roll);
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
