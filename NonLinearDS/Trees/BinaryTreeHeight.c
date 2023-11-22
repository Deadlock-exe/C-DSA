#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

// int heightBT(struct node* root){
//     struct node* ptr = root;
//     int left, right;
//     int height;
//     while(ptr != root){
//         if((ptr->left == NULL && ptr->right == NULL) || ptr == NULL){
//             return 0;
//         }
//         left = heightBT(ptr->left);
//         right = heightBT(ptr->right);
//         height = max(left, right) + 1;
//     }
//     return height;
// }

int heightBT(struct node* root){
    if (root == NULL) {
        return 0;  // Base case: an empty tree has height 0
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    int left = heightBT(root->left);
    int right = heightBT(root->right);
    
    return max(left, right) + 1;
}

int main(){
    struct node* root = NULL;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(8);
    root->right->right->left = createNode(9);

    printf("Height of tree is: %d\n", heightBT(root));
}
