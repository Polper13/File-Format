#include <stdio.h>
#include <string.h>

#include "rgb.h"

RGB getPixel(BMPDATA *bmpData, int x, int y)
{
    RGB rgb;

    unsigned char *pixel = bmpData->pixelData + y * bmpData->rowSize + x * 3;
    rgb.b = pixel[0];
    rgb.g = pixel[1];
    rgb.r = pixel[2];

    return rgb;
}

bool compare(RGB *rgb1, RGB *rgb2)
{
    // if (memcmp(rgb1, rgb2, sizeof(RGB)))
    //     return true;

    // return false;
    
    if (rgb1->r == rgb2->r &&
        rgb1->g == rgb2->g &&
        rgb1->b == rgb2->b)
    {
        return true;
    }

    return false;
}

void printRGB(RGB *rgb)
{
    printf("RGB: %u %u %u\n", (unsigned int)rgb->r, (unsigned int)rgb->g, (unsigned int)rgb->b);
}
