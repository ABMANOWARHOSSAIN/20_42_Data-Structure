//Tail Recursive Factorial

#include <stdio.h>

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

int main() {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);

    printf("Factorial of %u = %llu\n", num, factorial(num));

    return 0;
}
