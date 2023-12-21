#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct DoublyNode* createDoublyNode(int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertInMiddle(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0 || *head == NULL) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != NULL; ++i) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void insertAtBeginningDoubly(struct DoublyNode** head, int data) {
    struct DoublyNode* newNode = createDoublyNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEndDoubly(struct DoublyNode** head, int data) {
    struct DoublyNode* newNode = createDoublyNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct DoublyNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertInMiddleDoubly(struct DoublyNode** head, int data, int position) {
    struct DoublyNode* newNode = createDoublyNode(data);
    if (position == 0 || *head == NULL) {
        insertAtBeginningDoubly(head, data);
        return;
    }
    struct DoublyNode* temp = *head;
    for (int i = 0; i < position - 1 && temp->next != NULL; ++i) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteNodeDoubly(struct DoublyNode** head, int key) {
    struct DoublyNode* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void displayListDoubly(struct DoublyNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeListDoubly(struct DoublyNode** head) {
    struct DoublyNode* current = *head;
    struct DoublyNode* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Node* singlyHead = NULL;
    struct DoublyNode* doublyHead = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Middle\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&singlyHead, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&singlyHead, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertInMiddle(&singlyHead, data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&singlyHead, data);
                break;
            case 5:
                printf("Singly Linked List: ");
                displayList(singlyHead);
                break;
            case 6:
                freeList(&singlyHead);
                printf("Singly Linked List memory freed.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Middle\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginningDoubly(&doublyHead, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEndDoubly(&doublyHead, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertInMiddleDoubly(&doublyHead, data, position);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNodeDoubly(&doublyHead, data);
                break;
            case 5:
                printf("Doubly Linked List: ");
                displayListDoubly(doublyHead);
                break;
            case 6:
                freeListDoubly(&doublyHead);
                printf("Doubly Linked List memory freed.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

