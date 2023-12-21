#include <stdio.h>

// Function to move a disk from source peg to destination peg
void moveDisk(int disk, char source, char destination) {
    printf("Move disk %d from peg %c to peg %c\n", disk, source, destination);
}

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination, int *moveCount) {
    if (n == 1) {
        moveDisk(n, source, destination);
        (*moveCount)++;
    } else {
        towerOfHanoi(n - 1, source, destination, auxiliary, moveCount);
        moveDisk(n, source, destination);
        (*moveCount)++;
        towerOfHanoi(n - 1, auxiliary, source, destination, moveCount);
    }
}

int main() {
    int n, moveCount = 0;

    // Number of disks in Tower of Hanoi
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C', &moveCount);

    printf("\nTotal number of moves: %d\n", moveCount);

    return 0;
}
