#include "filterType.h"
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //float average1 = (float)(27 + 28 + 28)/3;
            //int average = round((float)(27 + 28 + 28)/3;);

            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int average = round((float)(red + green + blue) / 3);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed = round((float)(.393 * originalRed + .769 * originalGreen + .189 * originalBlue));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaGreen = round((float)(.349 * originalRed + .686 * originalGreen + .168 * originalBlue));

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            int sepiaBlue = round((float)(.272 * originalRed + .534 * originalGreen + .131 * originalBlue));

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //RGBTRIPLE tempImage[height][width];
    RGBTRIPLE(*tempImage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int x = (int)(width - 1 - j);
            
            int reflectedValueRed = image[i][j].rgbtRed;
            int reflectedValueGreen = image[i][j].rgbtGreen;
            int reflectedValueBlue = image[i][j].rgbtBlue;
            
            // assigning reflected values to temp array
            tempImage[i][x].rgbtRed = reflectedValueRed;
            tempImage[i][x].rgbtGreen = reflectedValueGreen;
            tempImage[i][x].rgbtBlue = reflectedValueBlue;
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // moving reflected pixels from temp array to original array used by main function
            image[i][j].rgbtRed = tempImage[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempImage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempImage[i][j].rgbtBlue;
        }
    }
    // imporant to free used memory
    free(tempImage);

    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tempImage)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for (int i = 0, sumRed, sumGreen, sumBlue, pixelCount; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            pixelCount = 1;
            sumRed = sumGreen = sumBlue = 0;
            
            //current cell value    
            sumRed = image[i][j].rgbtRed;
            sumGreen = image[i][j].rgbtGreen;
            sumBlue = image[i][j].rgbtBlue;
            
            //left cell value
            if (j > 0)
            {
                sumRed += image[i][j - 1].rgbtRed;
                sumGreen += image[i][j - 1].rgbtGreen;
                sumBlue += image[i][j - 1].rgbtBlue;
                pixelCount++;
            }
            //topleft cell value
            if (i > 0 && j > 0)
            {
                sumRed += image[i - 1][j - 1].rgbtRed;
                sumGreen += image[i - 1][j - 1].rgbtGreen;
                sumBlue += image[i - 1][j - 1].rgbtBlue;
                pixelCount++;
            }
            //top cell value
            if (i > 0)
            {
                sumRed += image[i - 1][j].rgbtRed;
                sumGreen += image[i - 1][j].rgbtGreen;
                sumBlue += image[i - 1][j].rgbtBlue;
                pixelCount++;
            }
            //topright cell value
            if (i > 0 && j < (width - 1))
            {
                sumRed += image[i - 1][j + 1].rgbtRed;
                sumGreen += image[i - 1][j + 1].rgbtGreen;
                sumBlue += image[i - 1][j + 1].rgbtBlue;
                pixelCount++;
            }
            //right cell value
            if (j < (width - 1))
            {   
                sumRed += image[i][j + 1].rgbtRed;
                sumGreen += image[i][j + 1].rgbtGreen;
                sumBlue += image[i][j + 1].rgbtBlue;
                pixelCount++;
            }
            //bottomright cell value
            if (i < (height - 1) && j < (width - 1))
            {
                sumRed += image[i + 1][j + 1].rgbtRed;
                sumGreen += image[i + 1][j + 1].rgbtGreen;
                sumBlue += image[i + 1][j + 1].rgbtBlue;
                pixelCount++;
            }
            //bottom cell value
            if (i < (height - 1))
            {
                sumRed += image[i + 1][j].rgbtRed;
                sumGreen += image[i + 1][j].rgbtGreen;
                sumBlue += image[i + 1][j].rgbtBlue;
                pixelCount++;
            }
            //bottomleft cell value
            if (i < (height - 1) && j > 0)
            {
                sumRed += image[i + 1][j - 1].rgbtRed;
                sumGreen += image[i + 1][j - 1].rgbtGreen;
                sumBlue += image[i + 1][j - 1].rgbtBlue;
                pixelCount++;
            }
            // assigning blurred pixels to temp array
            tempImage[i][j].rgbtRed = round((float)sumRed / pixelCount);
            tempImage[i][j].rgbtGreen = round((float)sumGreen / pixelCount);
            tempImage[i][j].rgbtBlue = round((float)sumBlue / pixelCount);
            
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //moving blurred pixels from temp array to original array used by main function
            image[i][j].rgbtRed = tempImage[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempImage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempImage[i][j].rgbtBlue;
        }
    }
    //important to free used memory
    free(tempImage);
    return;
}
