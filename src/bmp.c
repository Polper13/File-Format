#include "bmp.h"

#include <stdio.h>
#include <stdlib.h>

BMPDATA* readBmpFile(const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) 
    {
        perror("Failed to open file");
        return NULL;
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fp);

    if (fileHeader.bfType != 0x4D42) 
    {
        printf("Not a BMP file\n");
        fclose(fp);
        return NULL;
    }

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fp);

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int bitCount = infoHeader.biBitCount;

    if (bitCount != 24) 
    { // Obsługujemy tylko 24-bitowe BMP
        printf("Only 24-bit BMP files are supported\n");
        fclose(fp);
        return NULL;
    }

    int rowSize = (width * 3 + 3) & ~3; // Każdy wiersz musi mieć wielokrotność 4 bajtów
    unsigned char *pixelData = (unsigned char *)malloc(rowSize * height);
    fseek(fp, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, rowSize, height, fp);
    fclose(fp);

    BMPDATA* ptr = (BMPDATA*)malloc(sizeof(BMPDATA));
    ptr->width = width;
    ptr->height = height;
    ptr->rowSize = rowSize;
    ptr->pixelData = pixelData;

    return ptr;
}

void display(BMPDATA* bmpData)
{
    for (int y = 0; y < bmpData->height; y++) 
    {
        for (int x = 0; x < bmpData->width; x++) 
        {
            unsigned char *pixel = bmpData->pixelData + y * bmpData->rowSize + x * 3;
            unsigned char blue = pixel[0];
            unsigned char green = pixel[1];
            unsigned char red = pixel[2];
            printf("[%d, %d] : %d, %d, %d\n", x, y, red, green, blue);
        }
    }
}