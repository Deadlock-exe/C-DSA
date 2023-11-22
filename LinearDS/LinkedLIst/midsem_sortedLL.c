#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void printData(struct node *head){
    struct node *ptr = head;
    if(head == NULL){
        printf("empty LL");
    }
    else{
        while(ptr != 0){
            printf("%d ", ptr -> data);
            ptr = ptr->link;
        }
    }
}

struct node* insert(struct node *head, int x){
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = head;

    temp -> data = x;
    temp -> link = NULL;

    if(head == NULL || head -> data > x){
        temp -> link = head;
        head = temp;
    }

    else{
        while(ptr -> link != 0 && ptr->link->data < x){
            ptr = ptr -> link;
        }
        temp ->link = ptr -> link;
        ptr -> link = temp;
    }
    return head;
}

struct node* create(struct node *head){
    int x;
    int n;
    printf("enter number of integers: ");
    scanf("%d", &n);

    printf("enter integers: ");
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        head = insert(head, x);
    }

    return head;
}

int main(){
    struct node *head = NULL;
    head = create(head);

    printData(head);

}