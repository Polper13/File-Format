#pragma once

void printProgress(size_t count, size_t max)
{
    const int barWidth = 50;

    float progress = (float) count / max;
    int barLength = progress * barWidth;

    printf("\rProgress: [");
    for (int i = 0; i < barLength; ++i)
    {
        printf("#");
    }
    for (int i = barLength; i < barWidth; ++i)
    {
        printf(" ");
    }
    printf("] %.2f%%", progress * 100);

    fflush(stdout);
}