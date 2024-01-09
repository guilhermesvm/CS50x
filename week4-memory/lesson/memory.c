#include <stdio.h>
#include <stdlib.h>

//use 'valgrind ./memory' to check for memory leaks
int main(void){
    
    int *x = malloc(3 * sizeof(int));//malloc will store 3 times the size of an int
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}