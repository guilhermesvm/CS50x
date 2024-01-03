#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int n = 3;
int main(void){
    string names[] = {"Carter", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-323-605-5493", "+1-949-468-2750"};

    string name = get_string("Name: ");

    for(int i=0; i < n; i++){
        if(strcmp(names[i], name) == 0){
            printf("Found: %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
