#include <stdio.h>
#include <stdlib.h>

// doublely LL has 2 pointers one prev and one next on both sides

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void printData(struct node *head){
    if(head == NULL){
        printf("empty LL");
    }
    struct node *ptr = head;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

struct node* addToEmpty(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
    return head;
}

struct node* addToStart(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    // int data;
    // printf("enter number to add: ");
    // scanf("%d", &data);
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    temp -> next = head;
    head -> prev = temp;
    head = temp;
    return head;
}

struct node* addToEnd(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    struct node *tail = NULL;
    tail = head;

    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;

    while(tail -> next != NULL){
        tail = tail -> next;
    }

    temp -> prev = tail;
    tail -> next = temp;

    return head;

}

struct node* addToMid(struct node *head, int data, int position){
    struct node *temp = malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    struct node *before = NULL;
    struct node *after = NULL;

    before = head;
    after = head;

    while(position != 1){
        before = before -> next;
        position--;
    }
    if(before -> next == NULL){
        before -> next = temp;
        temp -> prev = before;
    }
   
    else{
        after = before -> next;

        before -> next = temp;
        temp -> prev = before;

        temp -> next = after;
        after -> prev = temp;
    }

    return head;
}

struct node* reverseDoubleLL(struct node *head){
    struct node *ptr1 = head;
    struct node *ptr2 = head -> next;

    ptr1 -> next = NULL;
    ptr1 -> prev = ptr2;

    while(ptr2 != NULL){
        ptr2 -> prev = ptr2 -> next;
        ptr2 -> next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2 -> prev;
    }

    head = ptr1;
    return head;

}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head = addToEmpty(head, 1);

    head = addToStart(head, 22);

    head = addToEnd(head, 999);

    head = addToMid(head, 300, 2);

    head = addToMid(head, 444, 4);      // adding to end using addToMid()

    printData(head);

    printf("\nreversing\n");

    head = reverseDoubleLL(head);

    printData(head);

    return 0;
}