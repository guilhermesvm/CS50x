#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct{
    string name;
    string number;
}person;

int main(void){
    person contacts[3];
    contacts[0].name = "Carter";
    contacts[0].number = "+1-617-495-1000";

    contacts[1].name = "David";
    contacts[1].number = "+1-323-605-5493";

    contacts[2].name = "John";
    contacts[2].number = "+1-949-468-2750";

    string name = get_string("Name: ");
    for(int i=0; i < 3; i++){
        if(strcmp(contacts[i].name, name) == 0){
            printf("Found %s\n", contacts[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
