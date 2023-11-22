#include <stdio.h>
#include <stdlib.h>



// malloc - allocates garbage value on initialization



// malloc allocates a large BLOCK of memory of a given size
// it works as see- " void *ptr = (type* )malloc(size_t size) " - yes it gives NULL pointer
// we make a pointer pointing to the large block of memory it creates and then we fill that memory by accessing it using pointer
// for example-



// int main(){
//     int n;
//     printf("enter number of integers: ");
//     scanf("%d", &n);
//     int *ptr = (int* )malloc(n*sizeof(int));

//     if(ptr == NULL){
//         printf("no memory allocated");
//         exit(1);
//     }
//     for(int i=0; i<n; i++){           // we are basically filling parts of that big block of memory one by one
//         printf("enter integer: ");
//         scanf("%d", ptr+i);                 // cuz ptr+i increases it by 4 everytime
//     }
//     for(int i=0; i<n; i++){
//         printf("%d ", *(ptr+i));        // we use * cuz now we need values that we stores inside those boxes
//     }
//     return 0;
// }








// calloc - allocates 0 value on initialization



// multiple blocks of memory
// needs 2 inputs instead of 1

// example- (int* )malloc(10*sizeof(int)) == (int* )calloc(10, sizeof(int))









// realloc 




//used to change size of memory block
// void *realloc(void *ptr, size_t newSize)

// ex- *ptr = (int* )malloc(sizeof(int))
// now ptr = (int* )realloc(ptr, 2*sizeof(int))      // makes the new size of each one as twice as earlier






int *inputSumn(){
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int *point = (int* )malloc(n*sizeof(int));

    return point;
}

int main(){
    int n;
    printf("enter number of integers: ");
    scanf("%d", &n);
    int *ptr = (int* )malloc(n*sizeof(int));

    if(ptr == NULL){
        printf("no memory allocated");
        exit(1);
    }

    printf("enter %d integers: \n", n);
    for(int i=0; i<n; i++){           // we are basically filling parts of that big block of memory one by one
        scanf("%d", ptr+i);                 // cuz ptr+i increases it by 4 everytime
    }

    ptr = (int* )realloc(ptr, 2*n*sizeof(int));     // using realloc

    printf("enter %d more integers: \n", n);
    for(int i=n; i<2*n; i++){
        scanf("%d", ptr+i);
    }

    for(int i=0; i<2*n; i++){
        printf("%d ", *(ptr+i));        // we use * cuz now we need values that we stores inside those boxes
    }
    return 0;


// we should release memory incaseof heap after use
// so- 

free(ptr);
ptr = NULL;

}
