#include <stdio.h>

int main(void){
    
    char *s = "HI!";    // == string s = "HI!"
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c\n", s[2]);   

    //pointer arithmetic
    printf("%c", *s);
    printf("%c", *(s+1));
    printf("%c", *(s+2));

}