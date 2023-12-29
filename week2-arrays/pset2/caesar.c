#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate(char c, int digits);


int main(int argc, string argv[]){

     if(argc != 2){
        printf("Error! You should type one command-line argument.\n");
        return 1;
    }

    string word = argv[1];
    int digits;

    if(!only_digits(word)){
        printf("Usage: ./caesar key\n");
        return 1;
    }else{
        digits = atoi(word);
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");

        for(int i=0; i < strlen(plainText); i++){
            printf("%c", rotate(plainText[i], digits));
        }
        printf("\n");
        return 0;
    }
}

bool only_digits(string text){
    for(int i=0; i < strlen(text); i++){
        if(!isdigit(text[i])){
            return false;
        }
    }
    return true;
}

char rotate(char c, int digits){
        if(isupper(c)){
           return ((c - 65 + digits) % 26) + 65; //YT help
        }else if(islower(c)){
           return ((c - 97 + digits) % 26) + 97; //YT help
        }else{
            return c;
        }

}
