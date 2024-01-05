#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    
   char *s = get_string("S: "); //HI!
   char *t = get_string("T: "); //HI!

    if(s == t){
        printf("Same\n");
    } else {
        printf("Different\n"); //They're different bc it's comparting the addresses of the chars array
    }

    printf("%p\n", s);
    printf("%p\n", t)

    //char *u = get_string("u: "); //HI!
    //char *x = get_string("X: "); //HI!

    // if(strcmp(u, x) == 0){
    //   printf("Same\n");  //It's the same cause strcmp it's comparing chars underneath the hood
    //} else {
    //    printf("Different\n");
    //}
}