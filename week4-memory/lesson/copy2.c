#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){

    char *s = get_string("s: ");

    //memory allocate - asks the system to find some number of bytes to create another s
    char *t = malloc(strlen(s) + 1); //number is lenght of s + 1 for the \0

    //This for loop can be replaced by strcopy()
    for(int i=0, n = strlen(s); i < n+1; i++){ 
        t[i] = s[i]; //t is pointing to the same string s, but s is in a different address
    }

    if(strlen(t) > 0){
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n",t);

    free(t); //free the number of bytes that were used
    return 0;
}