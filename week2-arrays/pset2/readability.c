#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index >= 16){
        printf("Grade 16+\n");
    } else if(index < 1){
        printf("Before Grade 1\n");
    } else{
        printf("Grade %i\n", index);
    }
}

int count_letters(string text){
    int total_letters = 0;
    for(int i = 0, len = strlen(text); i < len; i++){
        if(isalpha(text[i])){
            total_letters++;
       }
   }
   return total_letters;
}

int count_words(string text){
    int total_words = 1;
    for(int i=0, len = strlen(text); i <len; i++){
        if(text[i] == ' '){
            total_words++;
        }
    }
    return total_words;
}

int count_sentences(string text){
    int total_sentences = 0;
    for(int i=0, len = strlen(text); i < len; i++){
        if(text[i] == '.' || text[i] == '?' || text[i] == '!'){
            total_sentences++;
        }
    }
    return total_sentences;
}
