#include <stdio.h>
#include <stdlib.h>

// array implementation of queues

// top variable stays at the end

// front stays at first added, rear at last added

// if front = rear = -1 - empty queue but also when front = rear + 1 cuz front moves 1 aage when deleted

// no. of elements = rear-front+1

// when adding, add this too- if(front == -1) {front++}

//LL implementation

struct node{
    int data;
    struct node *link;
}*front=NULL, *rear=NULL;

void enqueue(struct node **front, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    temp -> link = *front;
    *front = temp;
}

int main(){

}