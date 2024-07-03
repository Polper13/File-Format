#pragma once

#include <stdbool.h>

// Struktura nagłówka pliku BMP
#pragma pack(push, 1)

typedef struct 
{
    unsigned short bfType;      // 2 bytes
    unsigned int bfSize;        // 4 bytes
    unsigned short bfReserved1; // 2 bytes
    unsigned short bfReserved2; // 2 bytes
    unsigned int bfOffBits;     // 4 bytes
} BITMAPFILEHEADER;

// Struktura nagłówka informacji BMP
typedef struct 
{
    unsigned int biSize;           // 4 bytes
    int biWidth;                   // 4 bytes
    int biHeight;                  // 4 bytes
    unsigned short biPlanes;       // 2 bytes
    unsigned short biBitCount;     // 2 bytes
    unsigned int biCompression;    // 4 bytes
    unsigned int biSizeImage;      // 4 bytes
    int biXPelsPerMeter;           // 4 bytes
    int biYPelsPerMeter;           // 4 bytes
    unsigned int biClrUsed;        // 4 bytes
    unsigned int biClrImportant;   // 4 bytes
} BITMAPINFOHEADER;

typedef struct 
{
    unsigned short width;
    unsigned short height;
    unsigned short rowSize;

    unsigned char *pixelData;
} BMPDATA;

#pragma pack(pop)

BMPDATA* readBmpFile(const char *filename);
void display(BMPDATA* bmpData);