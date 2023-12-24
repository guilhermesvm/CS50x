#include <stdio.h>
#include <cs50.h>   //library only avaible when logged into cs50.dev


int get_size(void);
void print_grid(int size);


int main(void){

    int n = get_size();
    print_grid(n);

}












// functions
int get_size(void){
    int n;
    do{
        n = get_int("Size: ");
    }
    while(n<1);
    return n;
}

void print_grid(int size){
    for(int row=0; row < size; row++){
        for(int column=0; column < size; column++){
            printf("#");
        }
        printf("\n");
    }
}


