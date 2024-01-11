#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define CARD_BYTES 512

// YT Help for this pset
// Video link: https://www.youtube.com/watch?v=AJiDIxGEszs&ab_channel=DevinFinley
// Video name: CS50 Recover - Week 4 - Recover Solution 2023. (Beginners Guide) - Week 4 Problem Set

int main(int argc, char *argv[]){
    // Accept a single command-line argument
    if(argc != 2){
        printf("You must type: ./recorver <FILE>\n");
        return 1;
    }

    // Open the memory card
    char *file = argv[1];

    FILE *card = fopen(file, "r");
    if(card == NULL){
        printf("Could not open.\n");
        return 2;
    }

    uint8_t buffer[CARD_BYTES]; // Create a buffer for a block of data.
    int countingImage = 0;      //Track numbers of generated images
    bool foundImage = false;    //To track if the image was found
    char imageName[8];          // Storing space for file name
    FILE *outptr = NULL;         // File pointer for recovered images

    // While there's still data left to read from the memory card
    while(fread(buffer, CARD_BYTES, 1, card)){
        // Checking the start of a new JPEG file
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            if(foundImage){
                fclose(outptr);
            }else{
                foundImage = true;
            }

        sprintf(imageName, "%03d.jpg", countingImage); //Generate the file name for the new JPEG image based on the countingImages variable

        outptr = fopen(imageName, "w");                 //Open a file with the generated name
        if(outptr == NULL){      //If the image wasn't created, it prints an error
            fclose(card);
            printf("Could not create %s.", imageName);
            return 3;
            }
            countingImage++;
        }
        
        //Write current block to the new JPEG file
        if(foundImage){
            fwrite(buffer, CARD_BYTES, 1, outptr);
         }
    }

    //Closing file
    fclose(card);

    //If the new image was found, close it
    if(foundImage){
        fclose(outptr);
    }

    return 0;
}
