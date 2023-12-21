//Simple Recursive Factorial

#include <stdio.h>

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);

    printf("Factorial of %u = %llu\n", num, factorial(num));

    return 0;
}
