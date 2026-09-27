/* A teacher wants to arrange student marks in ascending order and also measure how much rearrangement is necessary write a
C program using insertion sort that accepts n marks,displays the array every pass,counts the total number of element shifts,and 
displays the final sorted list and shift count */
//Source Code :
#include <stdio.h>

int main() {
    int n, i, j, key;
    int shifts = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter student marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    printf("\nInsertion Sort Passes:\n");

    for (i = 1; i < n; i++) {
        key = marks[i];
        j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j--;
            shifts++;
        }

        marks[j + 1] = key;

        // Display array after each pass
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", marks[k]);
        }
        printf("\n");
    }

    printf("\nFinal Sorted List: ");
    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }

    printf("\nTotal number of element shifts: %d\n", shifts);

    return 0;
}
