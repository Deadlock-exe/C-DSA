#include <stdio.h>
#include <stdlib.h>

// #define N 100
// int stack_arr[N];   // global declaration
// int top = -1;

// void push(int data){
//     if(top == N-1){
//         printf("stack overflow\n");
//         printf("cannot add %d", data);
//     }
//     else{
//         top++;
//         stack_arr[top] = data;
//     }
// }

// int pop(){
//     if(top == -1){
//         printf("stack underflow");
//         exit(1);
//     }
//     int popped;
//     popped = stack_arr[top];
//     top--;
//     return popped;
    
// }

// int main(){
//     push(1);
//     push(2);
//     push(3);
//     push(4);
//     int popped;
//     popped = pop();

//     printf("%d was popped\n", popped);
// }



// for LL implementation, we push and pop at the beginning of LL

struct node{
    int data;
    struct node *link;
} *top = NULL;


int isEmpty(struct node *top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct node *top){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));  // no memory available to allocate
    if(ptr == NULL){
        return 1;
    }
    else{
        return 0;
    }
    free(ptr);
    ptr = NULL;
}

void printData(struct node *top){
    struct node *ptr = top;
    if(top == NULL){
        printf("empty stack");
    }
    else{
        while(ptr != NULL){
            printf("%d ", ptr -> data);
            ptr = ptr -> link;
        }
    }
}

struct node* push(struct node* top, int value){
    if(isFull(top)){
        printf("stack overflow");
    }
    else{
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new -> data = value;
        new -> link = NULL;

        new -> link = top;
        top = new;

    }
    return top;

}

struct node* pop(struct node* top){
    if(isEmpty(top)){
        printf("stack underflow");
    }
    else{
        struct node* ptr = top;
        top = top -> link;
        int value;
        value = ptr -> data;

        printf("\n%d was popped\n", value);

        free(ptr);
        ptr = NULL;
    }
    return top;
}

int main(){

    top = push(top,10);
    top = push(top,22);
    top = push(top,8);

    printData(top);

    top = pop(top);

    printData(top);

    free(top);
    top = NULL;

}



// for paranthesis matching-
// put the left brackets in a stack and when a right bracket comes, pop the topmost one and match w the right one.

// if we come across a right one and stack is empty then right > left

// if at the end stack is not empty then left > right