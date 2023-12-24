#include <stdio.h>
#include <cs50.h>   //library only avaible when logged into cs50.dev

int main(void){

    string answer = get_string("What is your name? ");
    
    printf("Hello, %s!\n", answer ); //%s is a placeholder for a string, that says it's going to be substituted for a a variable
    printf("I got 100%% from my psets!\n");
}
