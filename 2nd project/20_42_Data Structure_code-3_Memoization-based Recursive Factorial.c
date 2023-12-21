//Memorization-based Recursive Factorial

#include <stdio.h>

// Define an array to store computed factorials
unsigned long long memo[20]; // Adjust the size as needed

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    // Check if the factorial is already computed
    if (memo[n] != 0) {
        return memo[n];
    } else {
        // If not computed, calculate and memoize
        memo[n] = n * factorial(n - 1);
        return memo[n];
    }
}

int main() {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);

    if (num < 20) {
        printf("Factorial of %u = %llu\n", num, factorial(num));
    } else {
        printf("Input too large for memoization example.\n");
    }

    return 0;
}
