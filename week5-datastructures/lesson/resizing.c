//Resizing arrays

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *list = malloc(3 * sizeof(int));  //Creating array list[3];
    if(list == NULL){
        return 1;
    }

    for(int i=0; i < 3; i++){  //Adding 1, 2, 3 to it
        list[i] = i+1;  
    }

    int *tmp = malloc(4 * sizeof(int));  //Creating now array tmp[4]
    if(tmp == NULL){
        free(list);
        return 1;
    }

    for(int i=0; i < 3; i++){   //Copying valus from list to tmp
        tmp[i] = list[i];
    }

    tmp[3] = 4;   //Adding last digit manually

    free(list);   //Getting rid of the original list, which now has garbage values
    
    list = tmp;   //List now has size 4

    for(int i=0; i < 4; i++){
        printf("%i ", list[i]);
    }
    
    free(list);

    return 0;
}