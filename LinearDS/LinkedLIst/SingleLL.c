#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void countNodes(struct node* head){
    if(head == NULL){
        printf("empty LL");
    }
    int count = 0;
    struct node *ptr = head;
    while(ptr!=NULL){
        count++;
        ptr = ptr -> link;
    }
    free(ptr);
    ptr = NULL;

    printf("Number of nodes are: %d\n", count);
}

void printData(struct node *head){
    if(head == NULL){
        printf("empty LL");
    }
    struct node *ptr = head;
    printf("Elements of LL are: ");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    free(ptr);
    ptr = NULL;
}

void addToEnd(struct node *head, int data){
    struct node *ptr = head;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link!=NULL){
        ptr = ptr->link;
    }

    ptr->link = temp;
}

struct node* addToStart(struct node **head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = *head;
    *head = temp;

    return *head;
}

void deleteFromEnd(struct node *head){
    struct node *ptr = head;
    struct node *temp = NULL;

    while(ptr->link->link!=NULL){
        ptr = ptr->link;
        temp = ptr;
    }
    ptr = ptr->link;

    temp->link = NULL;

    free(ptr);
    ptr = NULL;
}

struct node* deleteFromStart(struct node **head){
    struct node *temp = *head;
    *head = (*head)->link;

    free(temp);
    temp = NULL;

    return *head;
}

struct node* reverseLL(struct node **head){
    struct node *ptr = *head;
    struct node *prev = NULL;
    struct node *next = NULL;

    while(ptr!=NULL){
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }

    *head = prev;
    return *head;


}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 1;
    head -> link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current -> data = 57;
    current -> link = NULL;
    head -> link = current;

    countNodes(head);
    printData(head);

    printf("\n\n--Adding data at the end--\n\n");

    addToEnd(head, 35);
    countNodes(head);
    printData(head);

    printf("\n\n--Adding data at the start--\n\n");

    addToStart(&head, 20);
    countNodes(head);
    printData(head);

    printf("\n\n--Deleting from end--\n\n");

    deleteFromEnd(head);
    countNodes(head);
    printData(head);

    printf("\n\n--Deleting from start--\n\n");

    deleteFromStart(&head);
    countNodes(head);
    printData(head);

    printf("\n\n--Adding some elements--\n\n");

    addToEnd(head, 24);
    addToEnd(head, 89);
    addToEnd(head, 45);
    printData(head);


    printf("\n\n--Reversing LL--\n\n");
    reverseLL(&head);
    printData(head);

}
