//Fibonacci using recursive

#include <stdio.h>

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    } else {
        // Recursive case: F(n) = F(n-1) + F(n-2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    printf("Enter the value: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Please enter an non-negative integer.\n");
    } else {
        // Displaying Fibonacci sequence up to the nth term
        printf("Fibonacci sequence up to term %d: \n", n);
        for (int i = 0; i < n; ++i) {
            printf("%d \n", fibonacci(i));
        }
        printf("\n");
    }

    return 0;

}
