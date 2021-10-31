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
                
                
                /* Dynamic Programming C implementation of LCS problem */
#include<bits/stdc++.h>

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
int L[m+1][n+1];
int i, j;

/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
for (i=0; i<=m; i++)
{
	for (j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		L[i][j] = 0;

	else if (X[i-1] == Y[j-1])
		L[i][j] = L[i-1][j-1] + 1;

	else
		L[i][j] = max(L[i-1][j], L[i][j-1]);
	}
}
	
/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
return L[m][n];
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Driver program to test above function */
int main()
{
char X[] = "AGGTAB";
char Y[] = "GXTXAYB";

int m = strlen(X);
int n = strlen(Y);

printf("Length of LCS is %d", lcs( X, Y, m, n ) );

return 0;
}

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
