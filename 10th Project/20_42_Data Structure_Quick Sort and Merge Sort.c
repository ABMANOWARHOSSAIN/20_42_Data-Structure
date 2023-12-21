#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int middle, int right) {
    // ... (unchanged)
}

void mergeSort(int arr[], int left, int right) {
    // ... (unchanged)
}

int partition(int arr[], int low, int high) {
    // ... (unchanged)
}

void quickSort(int arr[], int low, int high) {
    // ... (unchanged)
}

int main() {
    int n, choice;

    do {
        // Choose sorting algorithm using switch
        printf("\nChoose sorting algorithm:\n");
        printf("1. Quick Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program.\n");
            exit(0);
        }

        // Get the size of the array
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);

        int arr[n];

        // Get array elements from the user
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                // Perform Quick Sort
                quickSort(arr, 0, n - 1);
                printf("\nSorted array using Quick Sort: ");
                break;
            case 2:
                // Perform Merge Sort
                mergeSort(arr, 0, n - 1);
                printf("\nSorted array using Merge Sort: ");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                continue; // Skip the rest of the loop and go back to the beginning
        }

        // Print the sorted array
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n\n");
    } while (1); // Infinite loop for returning to the menu

    return 0;
}
