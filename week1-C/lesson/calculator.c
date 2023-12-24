#include <stdio.h>
#include <cs50.h>   //library only avaible when logged into cs50.dev


int main(void){
    long x = get_long("x: ");
    long y = get_long("y: ");
    double z = (double) x/(double) y;  //x' and 'y' were 'long', they should be changed to 'float' to display numbers after the decimal point.
    printf("Result: %.20f\n", z);  //insted of using only %f, '%.{n}f' is used to set how many numbers will be displayed after the decimal point
}
