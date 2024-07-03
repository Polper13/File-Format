#include <stdio.h>
#include <time.h>

#include "fileWriter.h"

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
    RGB color;

    int lastNumber = 0;

    for (int y = 0; y < bmpData->height; y++) 
    {
        for (int x = 0; x < bmpData->width; x++) 
        {
            color = getPixel(bmpData, x, y);

            if (!listContains(list, &color))
                addToList(list, color);
        }

        int newNumber = y * 100 / bmpData->height;
        if (newNumber != lastNumber)
        {
            printf("%d procent\n", newNumber);
            lastNumber = newNumber;
        }   
    }

    end = clock();
    cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\ncolors: %d\n", list->length);
    printf("time: %d s %d ms\n", (int)cpuTimeUsed, (int)(cpuTimeUsed * 1000) % 1000);


    return list;
}
