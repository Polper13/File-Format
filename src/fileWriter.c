#include <stdio.h>
#include <time.h>

#include "fileWriter.h"
#include "progresBar.h"
#include "hash.h"

bool generateFile(BMPDATA *bmpData)
{
    FILE *file = fopen("output.kip", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return false;
    }

    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is a test.\n");

    fclose(file);

    printf("Data written to file successfully.\n");
    return true;
}

COLORLIST* scanColors(BMPDATA *bmpData)
{
    clock_t start, end;
    double cpuTimeUsed;

    start = clock();


    COLORLIST *list = createList(4);
    HASH *hash = createHash(4); 
    RGB color;

    int lastNumber = 0;

    for (int y = 0; y < bmpData->height; y++) 
    {
        for (int x = 0; x < bmpData->width; x++) 
        {
            color = getPixel(bmpData, x, y);

            // if (!listContains(list, &color))
            //     addToList(list, color);

            printf("[%d, %d] ", x, y);
            addToHash(hash, &color);
        }

        printProgress(y, bmpData->height - 1);
        printf("\n");
    }

    end = clock();
    cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    // printf("\ncolors: %d\n", list->length);
    int count = countElementsInHash(hash);
    // int count = hash->length;
    printf("\ncolors: %d\n", count);

    printRGB(&(*hash->data)->color);

    printf("time: %d s %d ms\n", (int)cpuTimeUsed, (int)(cpuTimeUsed * 1000) % 1000);


    return list;
}
