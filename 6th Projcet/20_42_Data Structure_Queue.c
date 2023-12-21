// Create a C program using Queue

#include <stdio.h>

#define MAX_SIZE 100

// Structure for queue
struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize empty queue
void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if queue is full
int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE -1);
}

// Function to add an element to queue or enqueue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0; // If the queue is empty, it set front to 0
    }

    queue->rear++;
    queue->array[queue->rear] = value;

    printf("%d enqueued to the queue.\n", value);
}

// Function to remove an element from queue or dequeue
int dequeue(struct Queue *queue) {
    int dequeueValue;

    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 to indicate an error
    }

    dequeueValue = queue->array[queue->front];
    queue->front++;

    // If the front becomes greater than the rear, reset front and rear to -1
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    return dequeueValue;
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements in the queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

/*

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 5);
    enqueue(&myQueue, 36);
    enqueue(&myQueue, 50);

    displayQueue(&myQueue);

    int dequeueValue = dequeue(&myQueue);
    if (dequeueValue != -1) {
        printf("Dequeued value: %d\n", dequeueValue);
    }

    displayQueue(&myQueue);

    return 0;
}

*/

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    int choice, value;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                break;

            case 2:
                value = dequeue(&myQueue);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                displayQueue(&myQueue);
                break;

            case 4:
                printf("Exit.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
