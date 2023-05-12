#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int findMax(Node* root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int findDepth(Node* root,int depth){
    int leftDepth = root->left == NULL ? -1 : findDepth(root->left, depth+1);
    int rigthDepth = root->right == NULL ? -1 : findDepth(root->right, depth+1);
    return ((leftDepth) >= (rigthDepth) ? (leftDepth+1) : (rigthDepth+1));
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 0);
 
    printf("Inorder traversal of binary search tree is: \n");
    inorderTraversal(root);
    printf("\nMin %i \n",findMin(root));
    printf("Max %i \n",findMax(root));
    printf("Depth of root %i \n",findDepth(root,0));
 
    return 0;
}