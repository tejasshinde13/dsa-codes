#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int findMin(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return -1;
    }
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->data;
}

void mirror(struct Node* root) {
    if (root == NULL) return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (key == root->data) return 1;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, n, i;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);
    printf("Enter values: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1) {
        printf("\n=== BST Operations ===\n");
        printf("1. Insert new node\n");
        printf("2. Find number of nodes in longest path (Height)\n");
        printf("3. Find Minimum value\n");
        printf("4. Mirror the tree\n");
        printf("5. Search a value\n");
        printf("6. Display Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Height (Longest path length): %d\n", height(root));
                break;

            case 3:
                value = findMin(root);
                if (value != -1)
                    printf("Minimum value in BST: %d\n", value);
                break;

            case 4:
                mirror(root);
                printf("Tree has been mirrored.\n");
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("%d found in BST.\n", value);
                else
                    printf("%d not found in BST.\n", value);
                break;

            case 6:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
