#include "helpers.h"
#include <math.h>

//I had YT help for this entire PSET, a teaching explaining/coding each function. It's better for me to actually take a look at the code, so I'm able to understand it
//Currently right know in my life, I don't dispose of 4-5-6 hours to think about one single problem.
//YT video name: (CS50) FILTER - PROBLEM SET 4 | SOLUTIONsubmit50 cs50/problems/2024/x/filter/less
// YT link: https://www.youtube.com/watch?v=r_5URERpuvQ&ab_channel=DorsCodingSchool
// Also used CS50's AI Duck as a help tool.

//It will define number for each color, to know which color we're working in that particular pixel
#define RED_COLOR 0
#define GREEN_COLOR 1
#define BLUE_COLOR 2

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]){
    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            int rgbtGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = rgbtGray;
            image[i][j].rgbtGreen = rgbtGray;
            image[i][j].rgbtRed = rgbtGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]){
    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            int sepiaRed = (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168  * image[i][j].rgbtBlue);
            int sepiaBlue = (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = round(fmin(255, sepiaRed));
            image[i][j].rgbtGreen = round(fmin(255, sepiaGreen));
            image[i][j].rgbtBlue = round(fmin(255, sepiaBlue));
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]){
    RGBTRIPLE aux;

    for(int i=0; i < height; i++){
        for(int j=0; j < width / 2; j++){
            aux = image[i][j];
            image[i][j] = image[i][width - j- 1];
            image[i][width - j- 1] = aux;
        }
    }
    return;
}


//Creating a function to return blur
int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int colorPosition){
    float count = 0;
    int sum = 0;
    for(int row = (i - 1); row <= (i + 1); row ++){
        for(int column = (j - 1); column <= (j + 1); column++){
            if(row < 0 || row >= height || column  < 0 || column >= width){
                continue;
            }

            if(colorPosition == RED_COLOR){
                sum += image[row][column].rgbtRed;
            } else if(colorPosition == GREEN_COLOR){
                sum += image[row][column].rgbtGreen;
            } else{
                sum += image[row][column].rgbtBlue;
            }
            count++;
        }
    }
    return round(sum / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]){
    RGBTRIPLE aux[height][width];

    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            aux[i][j] = image[i][j];
        }
    }

    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            image[i][j].rgbtRed = getBlur(i, j, height, width, aux, RED_COLOR);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, aux, GREEN_COLOR);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, aux, BLUE_COLOR);
        }
    }
    return;
}
