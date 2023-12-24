#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_marioGrid(int size);

int main(void)
{
   int height = get_size();
    print_marioGrid(height);
}

int get_size(void){
    int height;
    do{
        height = get_int("Height: ");
    }while(height < 1 || height > 8);
    return height;
}

void print_marioGrid(int height){
    for(int row = 0; row < height; row++){
        for(int space = height-1; space > row; space--){
            printf(" ");
        }
        for(int column=0; column <= row; column++){
            printf("#");
        }
        printf("\n");
     }

}
