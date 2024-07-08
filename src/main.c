#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"
#include "fileWriter.h"
#include "rgb.h"
#include "colorList.h"
#include "hash.h"

int main(int argc, char *argv[]) 
{
    // if (argc != 2) 
    // { 
    //     fprintf(stderr, "Usage: %s <file.bmp>\n", argv[0]);
    //     return 1;
    // }

    // BMPDATA* ptr = readBmpFile(argv[1]);

    // // display(ptr);
    // // printf("\n\n\n");
    
    // COLORLIST *list = scanColors(ptr);

    // freeList(list);

    // free(ptr->pixelData);
    // free(ptr);

    RGB color1 = (RGB){ 0, 5, 0 };
    RGB color2 = (RGB){ 5, 5, 0 };
    RGB color3 = (RGB){ 9, 0, 0 };

    // HASH *hash = createHash(10);
    // hash->length = 1;
    // hash->data[0] = createNode(&color1);

    struct NODE *list;
    addNewToNodes(list, &color1);

    // printRGB(&(list->color));

    // int count = countElementsInNodes(*hash->data);
    int count = countElementsInNodes(list);
    printf(">%d", count);

    return 0;
}
//spectrum.bmp benchmark
// 103354 colors

// linear
// 32s 156ms

