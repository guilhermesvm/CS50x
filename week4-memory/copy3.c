#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){

    char *s = get_string("s: "); //If user types a crazy long number, the pc might not have enough byes to allocate - returning NULL
                               
    if (s == NULL){ 
        return 1;
    }

    char *t = malloc(strlen(s) + 1); 

    if(t == NULL){
        return 1;  //exit program early
    }

    strcpy(t, s); //(t = s)

    if(strlen(t) > 0){
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n",t);

    free(t); 
    return 0;