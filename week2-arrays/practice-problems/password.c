#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    bool hasLower = false;
    bool hasUpper = false;
    bool hasNumber = false;
    bool hasSymbol = false;

    for(int i = 0; i < strlen(password); i++){
        if(islower(password[i])){
            hasLower = true;
        } else if(isupper(password[i])){
            hasUpper = true;
        } else if(isdigit(password[i])){
            hasNumber = true;
        } else if(ispunct(password[i])){
            hasSymbol = true;
        }
    }
    bool validPassword = hasLower && hasUpper & hasNumber && hasSymbol;
    return validPassword;
}
