#include <stdio.h>

int main(void){
    char c = get_char("Do you agree? (y or n)? ");

    if (c == 'y' || c == 'Y'){      // double quotes are for strings
        printf("Agreed.\n");        //single quotes are for chars
    }
    else if (c == 'n' || c == 'Y'){
        printf("Not agreed.\n");
    }
}
