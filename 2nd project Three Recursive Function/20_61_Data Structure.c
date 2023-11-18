#include <stdio.h>

// Simple Recursive Factorial
unsigned long long factorialSimple(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorialSimple(n - 1);
    }
}

// Tail Recursive Factorial
unsigned long long factorialTailRec(unsigned int n, unsigned long long result) {
    if (n == 0 || n == 1) {
        return result;
    } else {
        return factorialTailRec(n - 1, n * result);
    }
}

unsigned long long factorial(unsigned int n) {
    return factorialTailRec(n, 1);
}

// Memoization-based Recursive Factorial
unsigned long long memo[20]; // Adjust the size as needed

unsigned long long factorialMemo(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    // Check if the factorial is already computed
    if (memo[n] != 0) {
        return memo[n];
    } else {
        // If not computed, calculate and memoize
        memo[n] = n * factorialMemo(n - 1);
        return memo[n];
    }
}

int main() {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);

    // Simple Recursive Factorial
    printf("Simple Recursive Factorial of %u = %llu\n", num, factorialSimple(num));

    // Tail Recursive Factorial
    printf("Tail Recursive Factorial of %u = %llu\n", num, factorial(num));

    // Memoization-based Recursive Factorial
    if (num < 20) {
        printf("Memoization-based Recursive Factorial of %u = %llu\n", num, factorialMemo(num));
    } else {
        printf("Input too large for memoization example.\n");
    }

    return 0;
}
