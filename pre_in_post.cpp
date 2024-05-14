#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data        = data;
    newNode->left        = NULL;
    newNode->right       = NULL;
    return newNode;
}
void inorder(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            struct Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current            = current->left;
            } else {
                predecessor->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}
void preorder(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            struct Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                printf("%d ", current->data);  // Visit the node before going to the left subtree
                predecessor->right = current;
                current            = current->left;
            } else {
                predecessor->right = NULL;
                current            = current->right;
            }
        }
    }
}
void postorder(struct Node* root) {
    struct Node* dummy   = (struct Node*)malloc(sizeof(struct Node));
    dummy->left          = root;
    struct Node* current = dummy;
    while (current != NULL) {
        if (current->left == NULL) {
            current = current->right;
        } else {
            struct Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current            = current->left;
            } else {
                predecessor->right = NULL;
                struct Node* temp  = current->left;
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->right;
                }
                current = current->right;
            }
        }
    }
    free(dummy);
}
int main() {
    struct Node* root = createNode(3);
    root->left        = createNode(22);
    root->right       = createNode(2);
    root->left->left  = createNode(4);
    root->left->right = createNode(51);
    printf("Inorder traversal using link inversion: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal using link inversion: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal using link inversion: ");
    postorder(root);
    return 0;
}