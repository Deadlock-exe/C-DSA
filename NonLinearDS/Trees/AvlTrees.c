// height balanced BST is AVL tree

// to make it balanced, we gotta do rotations

// LL rotation when the existing tree only has left nodes i.e. each insertion is to the left

// RR rotation when existing tree only has right insertions

// LR when first left then right, i.e. skew tree
// 1 rotation on the R part converts it into LL

// RL rotation - first right then left, skew
// first on L part to make it RR then solve

// LL - right rotate
// RR - left rotate
// LR - left rotate then right rotate
// RL - right rotate then left rotate





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

int heightBT(struct node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    int left = heightBT(root->left);
    int right = heightBT(root->right);

    return max(left, right) + 1;
}

int isBalanced(struct node* root){
    int l=0, r=0, lh=0, rh=0, diff;
    if(root == NULL){
        return 1;       // NULL tree is balanced
    }
    l = isBalanced(root->left);
    r = isBalanced(root->right);
    if(l && r){
        lh = heightBT(root->left);
        rh = heightBT(root->right);
        diff = abs(lh-rh);
        if(diff <= 1){
            return 1;
        }
    }
    return 0;
}





// left rotation

// 1 - make b right subtree of A
// 2 - if P is null, make B as root
// 3 - if P not null - (if A leftChild, make B leftChild) and (if A rightChild, make B rightChild)
// 4 - make B parent of A

struct node* leftRotate(struct node* A){
    struct node* B  = A->right;
    A->right = B->left;
    B->left = A;
    return B;
}




// right rotation

// mirror the left rotation

struct node* rightRotate(struct node* B){
    struct node* A = B->left;
    B->left = A->right;
    A->right = B;
    return A;
}





void printData(struct node* root){
    if(root == NULL){
        return;
    }
    printData(root->left);
    printf("%d ", root->data);
    printData(root->right);
}






int main(){
    struct node* root = NULL;

    root = createNode(51);
    root->left = createNode(35);
    root->left->left = createNode(33);
    root->right = createNode(65);
    root->right->left = createNode(60);
    root->right->right = createNode(78);
    root->right->right->left = createNode(72);
    root->right->right->right = createNode(80);
    root->right->right->right->left = createNode(79);

    if(isBalanced(root)){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }

    printData(root);        // before left rotation
    printf("\n");

    printf("\nAfter left rotation\n");
    root->right = leftRotate(root->right);      // left rotation

    if(isBalanced(root)){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }

    printData(root);        // after left rotation
    printf("\n");

    printf("\nAfter right rotation\n");
    root->right = rightRotate(root->right);      // right rotation

    if(isBalanced(root)){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }

    printData(root);        // after right rotation
    printf("\n");

}
