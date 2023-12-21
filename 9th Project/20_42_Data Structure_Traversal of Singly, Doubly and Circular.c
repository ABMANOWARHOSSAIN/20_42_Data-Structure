#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Node structure for doubly linked list
struct DoubleNode {
    int data;
    struct DoubleNode* next;
    struct DoubleNode* prev;
};

// Node structure for circular linked list
struct CircularNode {
    int data;
    struct CircularNode* next;
};

// Function to traverse and print elements of a singly linked list
void traverseSingly(struct Node* head) {
    printf("Singly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to traverse and print elements of a doubly linked list
void traverseDoubly(struct DoubleNode* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to traverse and print elements of a circular linked list
void traverseCircular(struct CircularNode* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct CircularNode* current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to create a new node for a singly linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new node for a doubly linked list
struct DoubleNode* createDoubleNode(int data) {
    struct DoubleNode* newNode = (struct DoubleNode*)malloc(sizeof(struct DoubleNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a new node for a circular linked list
struct CircularNode* createCircularNode(int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* singlyHead = NULL;
    struct DoubleNode* doublyHead = NULL;
    struct CircularNode* circularHead = NULL;

    int n, data;

    // Creating singly linked list
    printf("Enter the number of elements for Singly Linked List: ");
    scanf("%d", &n);

    printf("Enter the elements for Singly Linked List:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        newNode->next = singlyHead;
        singlyHead = newNode;
    }

    // Creating doubly linked list
    printf("Enter the number of elements for Doubly Linked List: ");
    scanf("%d", &n);

    printf("Enter the elements for Doubly Linked List:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct DoubleNode* newNode = createDoubleNode(data);
        newNode->next = doublyHead;
        if (doublyHead != NULL) {
            doublyHead->prev = newNode;
        }
        doublyHead = newNode;
    }

    // Creating circular linked list
    printf("Enter the number of elements for Circular Linked List: ");
    scanf("%d", &n);

    printf("Enter the elements for Circular Linked List:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct CircularNode* newNode = createCircularNode(data);
        if (circularHead == NULL) {
            circularHead = newNode;
            newNode->next = circularHead;
        } else {
            newNode->next = circularHead->next;
            circularHead->next = newNode;
        }
    }

    // Traversing and printing the linked lists
    traverseSingly(singlyHead);
    traverseDoubly(doublyHead);
    traverseCircular(circularHead);

    // Freeing memory for singly linked list
    while (singlyHead != NULL) {
        struct Node* temp = singlyHead;
        singlyHead = singlyHead->next;
        free(temp);
    }

    // Freeing memory for doubly linked list
    while (doublyHead != NULL) {
        struct DoubleNode* temp = doublyHead;
        doublyHead = doublyHead->next;
        free(temp);
    }

    // Freeing memory for circular linked list
    struct CircularNode* current = circularHead;
    if (current != NULL) {
        do {
            struct CircularNode* temp = current;
            current = current->next;
            free(temp);
        } while (current != circularHead);
    }

    return 0;
}
