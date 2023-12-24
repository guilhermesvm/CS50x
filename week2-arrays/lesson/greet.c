// Prints a command-line argument

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }

    /*for (int i = 0; i < argc; i++) //To print as many arguments
    {
        printf("%s\n", argv[i]);
    }*?
}
