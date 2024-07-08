#include <stdlib.h>
#include <stdio.h>

#include "node.h"

struct NODE* createNode(RGB *color)
{
    struct NODE *ptr = (struct NODE*)malloc(sizeof(struct NODE));
    if (ptr == NULL)
    {
        printf("Could not allocate memory for creating node");
        exit(EXIT_FAILURE);
    }

    ptr->next = NULL;
    ptr->color = *color;

    return ptr;
}

void freeNodes(struct NODE* begining)
{
    struct NODE *temp;

    while (begining)
    {
        temp = begining;
        begining = begining->next;
        free(temp);
    }
}

// to change
// void addNewToNodes(struct NODE *list, RGB *color)
// {
//     if (*list == NULL)
//     {
//         *list = createNode(color);
//         printf("added 1 : ");
//         printRGB(&(*list)->color);
//         return;
//     }
//     while (1)
//     {
//         printf("1");

//         if (compare(&(*list)->color), color))
//             return;

//         printf("2");

//         if (list->next == NULL)
//         {
//             list->next = createNode(*color);
//             printf("added 2 : ");
//             printRGB(&(*list)->color);
//             return;
//         }

//         list = list->next;
//     }
// }

void addNewToNodes(struct NODE **list, RGB *color)
{
    struct NODE *ptr = *list;

    if (ptr == NULL)
    {
        *list = createNode(color);
        printf("added 1 : ");
        printRGB(&ptr->color);
        return;
    }
    while (1)
    {
        printf("1");

        if (compare(&ptr->color, color));
            return;

        printf("2");

        if (ptr->next == NULL)
        {
            ptr->next = createNode(color);
            printf("added 2 : ");
            printRGB(&ptr->color);
            return;
        }

        ptr = ptr->next;
    }
}

int countElementsInNodes(struct NODE *list)
{
    int count = 0;
    
    while (list)
    {
        count++;
        list = list->next;
    }

    return (count == 0 ? count : count - 1);
}