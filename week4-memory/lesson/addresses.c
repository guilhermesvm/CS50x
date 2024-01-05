#include <stdio.h>

//& ampersand to find the address where varaible is located
//* will to take to the location of that address to see what's there
//"%p" to print an address

int main(void){
    
    int n = 50;
    int *pointer = &n;

    printf("%p\n", &n);        //prints 0x123
    printf("%p\n", pointer);   //prints 0x123
    printf("%i\n", *pointer);  //prints 50
}