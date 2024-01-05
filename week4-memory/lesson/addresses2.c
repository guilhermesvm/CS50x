#include <stdio.h>
#include <cs50.h>

int main(void){
    
    string s = "HI!";
                    
    printf("%p\n", s);      //prints 0x123 - 's' points to the first char of 's'
    printf("%p\n", &s[0])   //prints 0x123
    printf("%p\n", &s[1])   //prints 0x124 (+1)
    printf("%p\n", &s[2])   //prints 0x125 (+2)
    printf("%p\n", &s[3])   //prints 0x126 (+3)
    
}