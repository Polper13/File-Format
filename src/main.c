#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "fileWriter.h"
#include "rgb.h"
#include "colorList.h"

struct MyStruct {
    char var1;
    char var2;
    char var3;
    char var4;
};

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    { 
        fprintf(stderr, "Usage: %s <file.bmp>\n", argv[0]);
        return 1;
    }

    BMPDATA* ptr = readBmpFile(argv[1]);

    // display(ptr);
    // printf("\n\n\n");
    
    COLORLIST *list = scanColors(ptr);

    freeList(list);

    free(ptr->pixelData);
    free(ptr);

    return 0;
}
//spectrum.bmp benchmark
// 103354 colors

// 3 compairsons
// 30s 350ms


// nazuna benchmark

// brute force
// 234s 163ms

// back approach
// 260s 702ms