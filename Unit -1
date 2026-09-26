#A Company Stores employee ids in ascendng order. Write a C program that accepts n employee IDs, searches for a required ID using Binary Search, displays its position when
found, reports when it is absent , and counts the number of comparisons . Test the program for both successful and unsuccessful searches .
#Source Code : 
#include <stdio.h>

int main() {
    int n, i, key;
    int low, high, mid;
    int comparisons = 0;
    int found = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    int emp[n];

    printf("Enter employee IDs in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &emp[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;

        if (emp[mid] == key) {
            printf("Employee ID %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        }
        else if (key < emp[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (!found) {
        printf("Employee ID %d is absent\n", key);
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
