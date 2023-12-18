#include <cs50.h>
#include <stdio.h>

int main(void)
{
     int startSize, endSize;
     int year = 0;

    // TODO: Prompt for start size
    do{
        startSize = get_int("Start size (minimum 9): ");
    }while(startSize < 9);

    // TODO: Prompt for end size
    do{
        endSize = get_int("End size: ");
    }while(endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    while(startSize < endSize){
        startSize = startSize + (startSize/3) - (startSize/4);
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}