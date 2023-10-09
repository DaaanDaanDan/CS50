#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            int avrg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed, sepiaBlue, sepiaGreen;
    int originalRed, originalGreen, originalBlue;

    for ( int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {

            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            
            sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i += 1)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j += 1)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }

        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j += 1)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary[height][width];

    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            int x_Red;
            int x_Green;
            int x_Blue;
            x_Red = x_Green = x_Blue = 0;
            float count = 0.00;

            for (int x = -1; x < 2; x += 1)
            {
                for (int y = -1; y < 2; y += 1)
                {
                    int inX = i + x;
                    int inY = j + y;

                    if (inX < 0 || inX > (height - 1) || inY < 0 || inY > (width - 1))
                    {
                        continue;
                    }

                    x_Red += image[inX][inY].rgbtRed;
                    x_Green += image[inX][inY].rgbtGreen;
                    x_Blue += image[inX][inY].rgbtBlue;

                    count += 1;
                }

                temporary[i][j].rgbtRed = round(x_Red / count);
                temporary[i][j].rgbtGreen = round(x_Green / count);
                temporary[i][j].rgbtBlue = round(x_Blue / count);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temporary[i][j].rgbtRed;
            image[i][j].rgbtGreen = temporary[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temporary[i][j].rgbtBlue;
        }
    }
    return;
}
