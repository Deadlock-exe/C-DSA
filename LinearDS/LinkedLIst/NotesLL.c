#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
// node is a self referential structure

// LL - counting elements is O(n) and printing data is also O(n)
// array - counting is O(1) and printing is O(n)

void countNodes(struct node *head){         // count the number of nodes using HEAD pointer
    int count = 0;
    if(head == NULL){
        printf("empty LL");
    }
    struct node *ptr = head;
    while(ptr != NULL){
        count++;
        ptr = ptr -> link;
    }
    printf("nodes are: %d\n", count);
}
void printData(struct node *head){
    if(head == NULL){
        printf("empty LL");
    }
    struct node *ptr = head;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }
}
void addAtEnd(struct node *head, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;
    struct node *ptr = head;
    while(ptr -> link != NULL){      // ptr -> link cuz we wanna add address of new node to the old node and not the ptr
        ptr = ptr -> link;
    }
    ptr -> link = temp;

}
struct node* addAtEndQuick(struct node *ptr, int data){         // adding a node one by one to the linkedlist
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
    return temp;
}
void addAtStart(struct node **head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    temp -> link = *head;
    *head = temp;
}
struct node* reverseLL(struct node **head){
    struct node *prev = NULL;
    struct node *next = NULL;
    struct node *ptr = *head;
    while(ptr != NULL){
        next = ptr -> link;        // moves temp2 aage
        ptr -> link = prev;        // puts NULL inside first node
        prev = ptr;                // puts node-1 ka address in temp1
        ptr = next;
    }       // when this ends, ptr and next both = NULL, so we do head = prev
    *head = prev;
    return *head;
}

int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head -> data = 45;
    head -> link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current -> data = 23;
    current -> link = NULL;
    head -> link = current;

    current = malloc(sizeof(struct node));
    current -> data = 8;
    current -> link = NULL;
    head -> link -> link = current;


    countNodes(head);
    printData(head);

    printf("\nnow we add a node at the end\n");

    addAtEnd(head, 100);
    printData(head);

    printf("\nnow we add nodes using quicker fn\n");

    struct node *ptr = head;
    ptr = addAtEndQuick(ptr, 2000);
    ptr = addAtEndQuick(ptr, 3000);
    ptr = addAtEndQuick(ptr, 4000);

    printData(head);


    printf("\nnow we add a node at the start\n");

    addAtStart(&head, 111);
    printData(head);

    printf("\nnow we reverse the LL\n");

    head = reverseLL(&head);
    printData(head);

    free(head);
    head = NULL;
    
    return 0;
}
