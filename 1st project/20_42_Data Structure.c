#include <stdio.h>

int linearSearch(int a[], int n, int data);
int binarySearch(int a[], int n, int data);
void bubbleSort(int arr[], int n);
void insertionSort(int a[], int n);

void printMenu() {
    printf("\n\t\t\t\033[1;35m========== Menu ==========\n");
    printf("\n\t\t\t\033[1;35mSelect a choice:\n");
    printf("\n\t\t\t\033[1;35m0.  End\n");
    printf("\n\t\t\t\033[1;35m1.  Linear Search\n");
    printf("\n\t\t\t\033[1;35m2.  Binary Search\n");
    printf("\n\t\t\t\033[1;35m3.  Bubble Sort\n");
    printf("\n\t\t\t\033[1;35m4.  Insertion Sort\n");
    printf("\n\t\t\t\033[1;35m============================\n");
    printf("\n\033[0m"); // Reset text color to default
}

int main() {
    int choice;

    do {
        printMenu();

        printf("\t\t\tSelect a choice: ");

        scanf("\n%d", &choice);

        switch(choice){

        case 0:
            printf("\nEnd");
            break;

        case 1:{
            // Linear Search
            int n,i,data;
            printf("\nEnter how many elements: ");
            scanf("%d",&n);
            int a[n];
            printf("\nEnter the elements..\n");
            for (i=0; i<n; i++){
                printf("Index[%d] = ",i);
                scanf("%d",&a[i]);
            }
            printf("\nWhich number you want to print: ");
            scanf("%d",&data);
            int result = linearsearch(a, n, data);
            break;
        }
        case 2:{
            //Binary Search
            int n, i, data;
            printf("\nEnter array size: ");
            scanf("%d", &n);
            int a[n];

            printf("\nEnter sorted array: \n");
            for (i = 0; i < n; i++){
                printf("Index[%d] = ",i);
                scanf("%d", &a[i]);
            }

            printf("\nEnter the element to search: ");
            scanf("%d", &data);

            int result = binarySearch(a, n, data);
            if (result != -1){
                printf("\nElement found at index %d\n", result);
            }
            else{
                printf("\nElement not found in the array\n");
            }
            break;
        }
        case 3:{
            //Bubble Sort
            int n, i, j, temp;
            printf("\nEnter array size: ");
            scanf("%d",&n);
            int a[n];
            printf("\nEnter the original array elements: ");
            for (i=0; i<n; i++){
                scanf("%d",&a[i]);
            }
            printf("\nOriginal array: ");
            for (i=0; i<n; i++){
                printf("%d ",a[i]);
            }
            printf("\n\n");
            bubbleSort(a,n);
            break;
        }
        case 4:{
            //insertion Sort
            int n, i, result;
            printf("\nEnter array size: ");
            scanf("%d",&n);
            int a[n];
            printf("\nEnter the elements: ");
            for (i=0; i<n; i++){
                scanf("%d",&a[i]);
            }
            printf("\nThe original elements are = ");
            for (i=0; i<n; i++){
                printf("%d ",a[i]);
            }
            insertionsort(a,n);
            break;
        }

        default:
            printf("\nInvalid choice. Please select a valid choice from the menu.\n");
            break;
        }


        printf("\n");
    }
    while(choice != 0);

    return 0;
}

int linearsearch(int a[], int n,int data ){
    {
        int i;
        for (i=0; i<n; i++){
            if (a[i]==data){
                printf("\nIndex no of %d is %d and\nThe position is %d\n",data, i,i+1);
                break;
            }
        }
        if (i==n){
            printf("\nNot Found!!\n");
        }
    }
}

int binarySearch(int a[], int n, int data)
{
    int low = 0;
    int high = n - 1;
    while (low <= high){
        int mid = low + (high - low) / 2; // Better way to calculate mid to avoid overflow
        if (data == a[mid])
            return mid;
        else if (data > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void bubbleSort(int a[], int n){
    //Do bubble sort
    int i,j,temp;
    for (i=0; i<n-1; i++){
        int flag = 0;
        for (j=0; j<n-1-i; j++){

            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
                printf("Swapped: %d and %d\n", a[j], a[j + 1]); // Print the swapping
            }
        }
        if (flag == 0)
            break;
    }
    printf("\nSorted array is: ");
    for (i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionsort(int a[], int n){
    int i,j,temp;
    for (i=1; i<n; i++){
        temp = a[i];
        j = i-1;
        while (j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    printf("\nSorted array is: ");
    for (i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
