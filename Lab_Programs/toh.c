// Write a c program to implement tower of hanoi problem and print 
// the count of number of operations required.

#include <stdio.h>
#include <math.h>

void towerOfHanoi(int n, char S, char M, char D){
    if(n == 1){
        printf("Move disk from %c to %c\n", S, D);
    }
    else{
        towerOfHanoi(n-1, S, D, M);
        printf("Move disk from %c to %c\n", S, D);
        towerOfHanoi(n-1, M, S, D);
    }
}

int main(){
    int n;
    printf("Enter number of disc: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'S', 'M', 'D');

    int count = pow(2, n);
    printf("Number of required operations: %d\n", count - 1);
    return 0; 
}