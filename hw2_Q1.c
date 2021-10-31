// Check if an array is stack permutation of other-
#include <stdio.h>
#include <stdlib.h>

int top=-1;
void push(int *arr, int num){
    top++;
    arr[top]=num;
}
int pop(int *arr){
    int num = arr[top];
    top--;
    return num;
}
int topElement(int *arr){
    return arr[top];
}
void printElements(int *arr){
    for(int i=0; i<=top; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int* stack;
    stack = (int*) malloc(100 * sizeof(int));
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int* inArr;
    inArr = (int*)malloc(n*sizeof(int));
    printf("Input Array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &inArr[i]);
    }

    int i=1, j=0;
    int possible = 1;
    while(i<=n){
        push(stack, i);
        if(stack[top]==inArr[j]){
            pop(stack);
            int x = top;
            j++;
            for(int k=0; k<x+1; k++){
                if(stack[top]==inArr[j]){
                    pop(stack);
                    j++;
                }
            }
        }
        i++;
    }
    // Checking the remaining elements in the stack matches with the input array-
    for(; j<n; j++){
        if(stack[top]!=inArr[j]){
            possible=0;
        }
        pop(stack);
    }
    
    if(possible){
        printf("Possible\n");

        int i=1, j=0;
        while(i<=n){
            push(stack, i);
            if(i==1){
                printf("push(%d)", i);
            }else{
                printf(", push(%d)", i);
            }
            if(stack[top]==inArr[j]){
                printf(", pop(%d)", pop(stack));
                int x = top;
                j++;
                for(int k=0; k<x+1; k++){
                    if(stack[top]==inArr[j]){
                        printf(", pop(%d)", pop(stack));
                        j++;
                    }
                }
            }
            i++;
        }
    }
    else{
        printf("Not possible\n");
    }

    // Deleting the dynamically allocated memory-
    free(stack);
    free(inArr);
    return 0;
}