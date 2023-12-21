#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to search for a node in the binary tree
struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Function to find the minimum value node in the binary tree
struct Node* findMinNode(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node with a given value from the binary tree
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to display the binary tree using inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to display the binary tree using preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to display the binary tree using postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to find the height of the binary tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to count the number of nodes in the binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the minimum value in the binary tree
int findMinValue(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum value in the binary tree
int findMaxValue(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Delete Node\n");
        printf("4. Display (Inorder Traversal)\n");
        printf("5. Display (Preorder Traversal)\n");
        printf("6. Display (Postorder Traversal)\n");
        printf("7. Find Height\n");
        printf("8. Count Nodes\n");
        printf("9. Find Minimum Value\n");
        printf("10. Find Maximum Value\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (searchNode(root, value) != NULL) {
                    printf("Node with value %d found in the tree.\n", value);
                } else {
                    printf("Node with value %d not found in the tree.\n", value);
                }
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 4:
                printf("Binary Tree (Inorder Traversal): ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Binary Tree (Preorder Traversal): ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Binary Tree (Postorder Traversal): ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Height of the Binary Tree: %d\n", findHeight(root));
                break;

            case 8:
                printf("Number of Nodes in the Binary Tree: %d\n", countNodes(root));
                break;

            case 9:
                printf("Minimum Value in the Binary Tree: %d\n", findMinValue(root));
                break;

            case 10:
                printf("Maximum Value in the Binary Tree: %d\n", findMaxValue(root));
                break;

            case 11:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 11);

    // Free memory allocated for the binary tree nodes before exiting
    // You may want to use a more sophisticated memory management approach in a real-world scenario
    // For simplicity, we are not handling memory cleanup thoroughly in this example
    return 0;
}
