#include <stdio.h>
int main()
{
    int pages[50], frames[10], recent[10];
    int n, f;
    int i, j, k;
    int pageFaults = 0;
    int found, pos, least;
    printf("========================================\n");
    printf("        LRU PAGE REPLACEMENT\n");
    printf("========================================\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }
    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++)
    {
        found = 0;
        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }
        if (found == 0)
        {
            pageFaults++;
            pos = -1;
            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }
            if (pos == -1)
            {
                least = recent[0];
                pos = 0;






  for (j = 1; j < f; j++)
                {
                    if (recent[j] < least)
                    {
                        least = recent[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            recent[pos] = i;
        }
        printf("%d\t", pages[i]);
        for (k = 0; k < f; k++)
        {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}
