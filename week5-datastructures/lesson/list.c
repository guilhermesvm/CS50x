//FIFO - First In First Out
#include <stdio.h>

int main(void){
    int list[3] = {0};
    for(int i=0; i < 3; i++){
        list[i] = i + 1;
    }

    for(int i=0; i < 3; i++){
        printf("%i\n", list[i]);
    }

    return 0;
}