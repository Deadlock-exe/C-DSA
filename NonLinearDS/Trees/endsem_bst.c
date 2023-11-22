// left > root > right

// in a balanced BST, diff b/w heights of left and right subtree of any node should be ATMAX 1

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
    if (root == NULL) {
        return -1;  // Base case: an empty tree has height 0
    }
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    int left = heightBT(root->left);
    int right = heightBT(root->right);
    
    return max(left, right) + 1;
}

int isBalanced(struct node* root){
    int l = 0, r = 0, lh = 0, rh = 0, diff = 0;
    if(root == NULL){
        return 1;
    }
    l = isBalanced(root->left);
    r = isBalanced(root->right);
    if(l && r){
        lh = heightBT(root->left);
        rh = heightBT(root->right);
        diff = abs((lh+1) - (rh+1));
        if(diff<=1){
            return 1;
        }
    }
    return 0;
}

struct node* recSearch(struct node* root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(root->data > key){
        return recSearch(root->left, key);
    }
    else if(root->data < key){
        return recSearch(root->right, key);
    }
    return root;
}

struct node* nonRecSearch(struct node* root, int key){
    while(root != NULL){
        if(root->data > key){
            root = root->left;
        }
        else if(root->data < key){
            root = root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
}





// smallest element in BST is leftmost element
// traversing to the leftmost node gives smallest element

struct node* recMin(struct node* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    else{
        return recMin(root->left);
    }
}

struct node* nonRecMin(struct node* root){
    if(root != NULL){
        while(root->left != NULL){
            root = root->left;
        }
    }
    return root;
}




// max element is rightmost
struct node* recMax(struct node* root){
    if(root == NULL){
        return NULL;
    }
    else if(root->right == NULL){
        return root;
    }
    else{
        return recMin(root->right);
    }
}

struct node* nonRecMax(struct node* root){
    if(root != NULL){
        while(root->right != NULL){
            root = root->right;
        }
    }
    return root;
}





// for insertion, we use 2 pointers for traversal

struct node* nonRecInsert(struct node* root, int ikey){
    struct node* ptr = root;
    struct node* prev = NULL;
    struct node* temp = createNode(ikey);
    while(ptr != NULL){
        prev = ptr;
        if(ikey < ptr->data){
            ptr = ptr->left;
        }
        else if(ikey > ptr->data){
            ptr = ptr->right;
        }
        else{
            printf("Duplicate key\n");
            return root;
        }
    }
    if(prev == NULL){
        root = temp;
        printf("Created a binary tree with root element %d\n", ikey);
    }
    else if(ikey > prev->data){
        prev->right = temp;
        printf("Added %d to the right of %d\n", ikey, prev->data);
    }
    else{
        prev->left = temp;
        printf("Added %d to the left of %d\n", ikey, prev->data);
    }
    return root;
}

struct node* recInsert(struct node* root, int ikey2){
    if(root == NULL){
        root = createNode(ikey2);
    }
    else if(root->data > ikey2){
        root->left = recInsert(root->left, ikey2);
    }
    else if(root->data < ikey2){
        root->right = recInsert(root->right, ikey2);
    }
    else{
        printf("Duplicate key\n");
    }
    return root;
}





// to delete, we have 3 cases - 0 children, 1 child, 2 children

struct node* case1(struct node* root, struct node* ptr, struct node* prev){         // case 1 - no children
    if(prev == NULL){
        root = NULL;
    }
    else if(ptr == prev->left){
        prev->left = NULL;
    }
    else if(ptr == prev->right){
        prev->right = NULL;
    }
    free(ptr);
    return root;
}

struct node* case2(struct node* root, struct node* ptr, struct node* prev){         // 1 child
    struct node* child;
    if(ptr->left != NULL){
        child = ptr->left;
    }
    else if(ptr->right != NULL){
        child = ptr->right;
    }

    if(ptr == prev->left){
        prev->left = child;
    }
    else if( ptr == prev->right){
        prev->right = child;
    }
    free(ptr);
    return root;
}

struct node* case3(struct node* root, struct node* ptr, struct node* prev){         // 2 children
    struct node* leftChild = ptr->left;
    struct node* rightChild = ptr->right;

    if(prev == NULL){
        leftChild = root;
        leftChild->right = rightChild;
    }

    prev->left = leftChild;
    prev->right = rightChild;

    free(ptr);
    return root;
}


struct node* nonRecDelete(struct node* root, int dkey){
    struct node *ptr =  root;
    struct node *prev = NULL;
    while(ptr != NULL){
        if(dkey == ptr->data){
            break;
        }
        prev = ptr;
        if(dkey < ptr->data){
            ptr = ptr->left;
        }
        else if(dkey > ptr->data){
            ptr = ptr->right;
        }
    }
    if(ptr->left == NULL && ptr->right == NULL){    // checking leaf node that is for CASE 1
        root = case1(root, ptr, prev);
    }
    else if(ptr->left != NULL || ptr->right != NULL){
        root = case2(root, ptr, prev);
    }
    else if(ptr->left != NULL && ptr->right != NULL){
        root = case3(root, ptr, prev);
    }
    else{   
        printf("Invalid\n");
    }
    return root;
}






// inorder traversal in BST gives ascending order
// used to check if everything is right

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
    root = createNode(67);
    root->left = createNode(34);
    root->right = createNode(80);
    root->left->left = createNode(10);
    root->left->right = createNode(55);
    root->left->right->left = createNode(45);
    root->left->right->right = createNode(60);

    if(isBalanced(root)){
        printf("Balanced\n");                           // if tree is balanced
    }
    else{
        printf("Not balanced\n");
    }

    int key;
    printf("Enter element to find: ");      
    scanf("%d", &key);                                  // searching key

    if(nonRecSearch(root, key) == NULL){
        printf("%d not found\n", key);
    }
    else{
        printf("Found %d without recursion\n", key);
    }

    if(recSearch(root, key) == NULL){
        printf("%d not found\n", key);
    }
    else{
        printf("Found %d using recursion\n", key);
    }   

    printf("\n");
    printData(root);
    printf("\n");

    printf("Minimum element without recursion is: %d\n", nonRecMin(root)->data);        // min
    printf("Minimum element using recursion is: %d\n", recMin(root)->data);

    printf("Max element without recursion is: %d\n", nonRecMax(root)->data);            // max
    printf("Max element using recursion is: %d\n", recMax(root)->data);


    int ikey;
    printf("Enter element to insert without recursion: ");
    scanf("%d", &ikey);

    nonRecInsert(root, ikey);     // inserting ikey without recursion

    printf("\n");
    printData(root);
    printf("\n");

    int ikey2;
    printf("Enter element to insert using recursion: ");
    scanf("%d", &ikey2);
    recInsert(root, ikey2);        // inserting ikey using recursion

    printf("\n");
    printData(root);
    printf("\n");

    int dkey;
    printf("Enter element to delete: ");
    scanf("%d", &dkey);
    nonRecDelete(root, dkey);      // deleting dkey

    printf("\n");
    printData(root);
    printf("\n");
}
