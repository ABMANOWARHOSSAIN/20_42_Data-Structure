#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size, int order, char showSteps) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((order == 1 && arr[j] > arr[j + 1]) || (order == 2 && arr[j] < arr[j + 1])) {
                swap(&arr[j], &arr[j + 1]);
                if (showSteps == 'y') {
                    printArray(arr, size);
                }
            }
        }
    }
}

void insertionSort(int arr[], int size, int order, char showSteps) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while ((order == 1 && j >= 0 && arr[j] > key) || (order == 2 && j >= 0 && arr[j] < key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        if (showSteps == 'y') {
            printArray(arr, size);
        }
    }
}

void selectionSort(int arr[], int size, int order, char showSteps) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if ((order == 1 && arr[j] < arr[minIndex]) || (order == 2 && arr[j] > arr[minIndex])) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);

        if (showSteps == 'y') {
            printArray(arr, size);
        }
    }
}

void merge(int arr[], int l, int m, int r, int order, char showSteps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if ((order == 1 && L[i] <= R[j]) || (order == 2 && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;

        if (showSteps == 'y') {
            printArray(arr, r - l + 1);
        }
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

        if (showSteps == 'y') {
            printArray(arr, r - l + 1);
        }
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

        if (showSteps == 'y') {
            printArray(arr, r - l + 1);
        }
    }
}

void mergeSort(int arr[], int l, int r, int order, char showSteps) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, order, showSteps);
        mergeSort(arr, m + 1, r, order, showSteps);

        merge(arr, l, m, r, order, showSteps);
    }
}

int partition(int arr[], int low, int high, int order, char showSteps) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if ((order == 1 && arr[j] < pivot) || (order == 2 && arr[j] > pivot)) {
            i++;
            swap(&arr[i], &arr[j]);

            if (showSteps == 'y') {
                printArray(arr, high - low + 1);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);

    if (showSteps == 'y') {
        printArray(arr, high - low + 1);
    }

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int order, char showSteps) {
    if (low < high) {
        int pi = partition(arr, low, high, order, showSteps);

        quickSort(arr, low, pi - 1, order, showSteps);
        quickSort(arr, pi + 1, high, order, showSteps);
    }
}

// Implement other sorting algorithms (Heap, Counting, Radix, Bucket) here

void heapify(int arr[], int n, int i, int order, char showSteps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ((order == 1 && arr[left] > arr[largest]) || (order == 2 && arr[left] < arr[largest]))) {
        largest = left;
    }

    if (right < n && ((order == 1 && arr[right] > arr[largest]) || (order == 2 && arr[right] < arr[largest]))) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        if (showSteps == 'y') {
            printArray(arr, n);
        }

        heapify(arr, n, largest, order, showSteps);
    }
}

void heapSort(int arr[], int n, int order, char showSteps) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, order, showSteps);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        if (showSteps == 'y') {
            printArray(arr, n);
        }

        heapify(arr, i, 0, order, showSteps);
    }
}

void countingSort(int arr[], int n, int order, char showSteps) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int output[n];
    int k = 0;

    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[k++] = i;
            count[i]--;

            if (showSteps == 'y') {
                printArray(arr, n);
            }
        }
    }
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSortRadix(int arr[], int n, int exp, int order, char showSteps) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];

        if (showSteps == 'y') {
            printArray(arr, n);
        }
    }
}

void radixSort(int arr[], int n, int order, char showSteps) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSortRadix(arr, n, exp, order, showSteps);
    }
}

void bucketSort(int arr[], int n, int order, char showSteps) {
    const int num_buckets = 10;
    int buckets[num_buckets][n];

    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < n; j++) {
            buckets[i][j] = -1;
        }
    }

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_range = (max_val + 1) / num_buckets;

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / bucket_range;
        int j = 0;
        while (buckets[bucket_index][j] != -1) {
            j++;
        }
        buckets[bucket_index][j] = arr[i];

        if (showSteps == 'y') {
            printf("Bucket %d: ", bucket_index);
            printArray(buckets[bucket_index], n);
        }
    }

    int k = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j] != -1) {
                arr[k++] = buckets[i][j];

                if (showSteps == 'y') {
                    printArray(arr, n);
                }
            }
        }
    }
}

int main() {
    int choice, size, order;
    char showSteps;

    do {
        system("cls"); // Clear screen (for Windows)

        // Color codes
        printf("\033[1;36m"); // Cyan text

        // Header
        printf("===========================================\n");
        printf("             Sorting Algorithm Menu         \n");
        printf("===========================================\n");

        // Menu options
        printf(" 1. Bubble Sort\n");
        printf(" 2. Insertion Sort\n");
        printf(" 3. Selection Sort\n");
        printf(" 4. Merge Sort\n");
        printf(" 5. Quick Sort\n");
        printf(" 6. Heap Sort\n");
        printf(" 7. Counting Sort\n");
        printf(" 8. Radix Sort\n");
        printf(" 9. Bucket Sort\n");
        printf(" 0. Exit\n");

        // Color reset
        printf("\033[0m"); // Reset text color

        // User input
        printf("Enter your choice (0-8): ");
        scanf("%d", &choice);



        if (choice == 0) {
            break;
        }

        printf("Enter the size of the array: ");
        scanf("%d", &size);

        int arr[size];

        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }

        printf("Choose sorting order:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("Enter your choice: ");
        scanf("%d", &order);

        printf("Do you want to see each step of sorting? (y for Yes, n for No): ");
        scanf(" %c", &showSteps);

        switch (choice) {
            case 1:
                bubbleSort(arr, size, order, showSteps);
                break;
            case 2:
                insertionSort(arr, size, order, showSteps);
                break;
            case 3:
                selectionSort(arr, size, order, showSteps);
                break;
            case 4:
                mergeSort(arr, 0, size - 1, order, showSteps);
                break;
            case 5:
                quickSort(arr, 0, size - 1, order, showSteps);
                break;
            case 6:
                heapSort(arr, size, order, showSteps);
                break;
            case 7:
                countingSort(arr, size, order, showSteps);
                break;
            case 8:
                radixSort(arr, size, order, showSteps);
                break;
            case 9:
                bucketSort(arr, size, order, showSteps);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\nSorted Array: ");
        printArray(arr, size);

        printf("\nDo you want to continue sorting? (y for Yes, n for No): ");
        scanf(" %c", &showSteps);
    } while (showSteps == 'y');

    return 0;
}
