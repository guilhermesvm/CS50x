// Determines the length of a string

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt for user's name
    string name = get_string("Name: ");
    int n = strlen(name);

    printf("Total letters: %i\n", n);

    /* Count number of characters up until '\0' (aka NUL), but there's already a function
    int n = 0;
    while (name[n] != '\0')
    {
        n++;
    }*/
}
