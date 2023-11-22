// height = number of levels
// depth = level
// degree = number of children of a node
// path length = number of nodes in the path

// binary tree - each node has ATMOST 2 children
// left child < node < right node (values) - binary search tree - takes O(logn) time

// max nodes at a level = 2^level
// sum of nodes = 2^0 + 2^1 + .... 2^last-level = GP = 2^height - 1
// minimum number of ndoes in a tree = height (1 node at each level) - skew tree
// if n nodes - max height = n and min height = log(n+1)(base 2) - we take next integer (if 4.08 then height = 5)
// n(0) = n(2) + 1
// sum of degrees of al vertices =  2 X number of edges
// in k-ary tree with 0 OR k children - leaf nodes L = (k-1)xi + 1 (i = internal nodes)

// full binary tree - every node has 0 or k children
// complete binary tree - every level is full and last level is filled from the left - HEAP

// if node at k then left child at index (2k+1)
// if node at k then right child at index (2k+2)
// if node at k then parents at (k-1)/2 (floor division)

// if we start numbering K from 1, then - left child at 2K, right child at 2K+1, parent at [K/2]







// array implementation of binary tree - formula based




// #include <stdio.h>
// #include <stdlib.h>

// #define n 10

// char tree[n];       // global array has all elements '\0' by default

// void root(char c){
//     if(tree[0] != '\0'){
//         printf("Root already exists\n");
//     }
//     else{
//         tree[0] = c;
//     }
// }

// void left(char c, int parent){
//     if(tree[parent] == '\0'){
//         printf("Parent does not exist, cannot insert %c\n", c);
//     }
//     else{
//         tree[2*parent+1] = c;       // left child is at 2k+1
//     }
// }

// void right(char c, int parent){
//     if(tree[parent] == '\0'){
//         printf("Parent does not exist, cannot insert %c\n", c);
//     }
//     else{
//         tree[2*parent+2] = c;       // right child is at 2k+2
//     }
// }

// void printData(){
//     for(int i=0; i<n; i++){
//         if(tree[i] == '\0'){
//             printf("* ");
//         }
//         else{
//             printf("%c ", tree[i]);
//         }
//     }
// }

// int main(){
//     root('A');
//     left('B', 0);
//     right('C', 0);
//     right('D', 2);
//     right('E', 3);

//     printData();
// }






// linked implementation
// n nodes - 2n links - n-1 edges = n-1 links - n+1 left i.e. n+1 are NULL links




// logic - 

// root node{
//     1. allocate memory
//     2. put data
//     3. transfer control to left node
//     left node{
//         1. allocate memory 
//         2. put data 
//         3. transfer control to left node(till we get NULL)
//         4. transfer control to right node(till we get NULL)
//         5. return address back to root node
//     }
//     4. transfer control to right node
//     right node{
//         1. allocate memory 
//         2. put data 
//         3. transfer control to left node(till we get NULL)
//         4. transfer control to right node(till we get NULL)
//         5. return address back to root node
//     }
//     5. return address back to caller

// }


#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right;
};

struct node* createTree();
int isFullBT(struct node*);
int countNodes(struct node*);
int isCompleteBT(struct node*, int, int);


int main(){
    struct node* root = createTree();
    printf("%d ", root->data);
    printf("%d ", root->left->data);
    printf("%d ", root->right->data);

    if(isFullBT(root)){
        printf("Full binary tree\n");
    }
    else{
        printf("Not full\n");
    }

    int index = 0;
    int count = countNodes(root);
    printf("Number of nodes are: %d\n", count);

    if(isCompleteBT(root,index,count)){
        printf("Complete binary tree\n");
    }
    else{
        printf("Not complete\n");
    }

    return 0;
}


struct node* createTree(){
    int input, data;
    printf("Do you wanna insert new node?(0 for no, 1 for yes): ");
    scanf("%d", &input);
    if(!input){
        return NULL;
    }
    else{
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);
        newNode -> data = data;

        printf("Left child of %d\n", newNode -> data);
        newNode -> left = createTree();

        printf("Right child of %d\n", newNode -> data);
        newNode -> right = createTree();

        return newNode;
    }
}





// full binary tree



// i internal nodes then L = (k-1)i+1 = i+1 leaf nodes
// so total nodes  = 2i+1 = 2L-1


int isFullBT(struct node* root){

    int left, right; 
    if(root == NULL){
        return 1;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    if(root->left && root->right){
        left = isFullBT(root->left);
        right = isFullBT(root->right);
        return (left && right);
    }
    return 0;
}





// complete binary tree



// if n nodes - and k is such that 1 to n then
// k=1 is root node
// k>1 then floor(k/2) is parent node
// if 2k>n then no left child
// 2k+1>n then no right child

// if height h then
// max nodes = 2^h - 1 - when last level is full
// min nodes = 2^(h-1) - when last level has 1 node - so second last level full + 1


int countNodes(struct node* root){
    if(root == NULL){
        return 0;
    }
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return (1+left+right);
    }
}

// to check if complete binary tree - we see if index > number of nodes
// cuz ex. next left child is at 2i+1, if 2i+1 > n then this means not complete binary tree

int isCompleteBT(struct node* root, int i, int count){
    if(root == NULL){
        return 1;
    }
    else if(i >= count){   
        return 0;
    }
    int left = isCompleteBT(root->left, 2*i+1, count);
    int right = isCompleteBT(root->right, 2*i+2, count);
    return (left && right);
}
