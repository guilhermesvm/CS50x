#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    string word = argv[1];
    if(argc != 2){
        printf("Error! You must type one command-line argument.\n");
        return 1;
    }else{
        printf("%s\n", replace(word));
    }
}

string replace(string word){
    for(int i=0, length = strlen(word); i < length; i++){
        char letter = word[i];
        switch(letter){
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                word[i] = letter;
        }
    }
    return word;
}
