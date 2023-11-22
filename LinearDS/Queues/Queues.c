#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

void printData(struct queue* q){
    int ptr;
    ptr = q->f+1;
    while(ptr <= q->r){
        printf("%d\n", q->arr[ptr]);
        ptr++;
    }
}

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    else return 0;
}

int isFull(struct queue *q){
    if(q->r == q->size -1){
        return 1;
    }
    else return 0;
}

void enqueue(struct queue* q, int value){
    if(isFull(q)){
        printf("queue overflow");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
    }
}

void dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("queue underflow");
    }
    else{
        q->f++;
        printf("%d was dequeued\n", q->arr[q->f]);
    }
}

int main(){
    struct queue *q = (struct queue *)malloc((sizeof(struct queue)));
    q -> size = 10;
    q -> f = -1;
    q -> r = -1;
    q -> arr = (int *)malloc(q->size*sizeof(int));

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printData(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);

    printData(q);

    free(q);
    q = NULL;

}



// for queue using LL, insertion at end and deletion at beginning i.e the new ones get added at the end and the first ones stay at the starting
