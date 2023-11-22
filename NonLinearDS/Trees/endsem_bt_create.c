// to create a unique binary tree, we need inorder traversal

// using inorder and preorder
// preorder tells us the root node and inorder tells us the left and right trees
// for example - 
// preorder - ABDECFGH
// we can tell A is root node
// inorder - DEBAFCHG
// this is - DEB-A-FCHG
// then using the preorder(BDE), we can tell B is the root node for left subtree
// so - DE-B-A-C-FGH
// and so on


// 2 arrays

// find root
// see left and right
// find their roots
// recursion

// from 0 to index of root - find a root->left 
// from index to end - find a root->right 
// repeat

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the index of a value in the inorder traversal
int findInorderIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct a binary tree from inorder and preorder traversals
struct TreeNode* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // The first element in preorder is the root
    struct TreeNode* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // Find the index of the root in the inorder traversal
    int inorderIndex = findInorderIndex(inorder, inStart, inEnd, root->data);

    // Recursively build the left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inorderIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inorderIndex + 1, inEnd, preIndex);

    return root;
}

// Function to print the inorder traversal of a binary tree
void printInorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preIndex = 0;

    int n = sizeof(preorder) / sizeof(preorder[0]);

    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
