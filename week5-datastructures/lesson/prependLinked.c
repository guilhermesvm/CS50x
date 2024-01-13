#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[]){
    node *list = NULL;

    for(int i=1; i < argc; i++){
        int number = atoi(argv[i]);     //converting number the user typed in to int

        node *n = malloc(sizeof(node));
        if(n == NULL){
            // free memory thus far
            return 1;
        }

        n->number = number;
        n->next = list;

        list = n;
    }

    //Print whole list
    node *ptr = list;
    while(ptr != NULL){
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
}
