#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){

    char *s = get_string("s: "); //hi!
    char *t = s;

    if(strlen(t) > 0){
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);   //Hi!
    printf("%s\n",t);   //Hi! - both are capitalized, cause they're pointing at the same address
}