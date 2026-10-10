#include <stdio.h>
int main()
{
    int pages[50], frames[10];
    int n, f;
    int i, j, k;
    int pageFaults = 0;
    int found, pos;
    int farthest, nextUse;
    printf("========================================\n");
    printf("      OPTIMAL PAGE REPLACEMENT\n");
    printf("========================================\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
        frames[i] = -1;
    printf("\nPage\tFrames\n");
    for (i = 0; i < n; i++)
    {
        found = 0;
 for (j = 0; j < f; j++)
        {
  if (frames[j] == pages[i])
            {
                found = 1;
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
                farthest = -1;
                pos = 0;
  for (j = 0; j < f; j++)
                {
                    nextUse = -1;
                    for (k = i + 1; k < n; k++)
  		{
   		if (frames[j] == pages[k])
                        {
                            nextUse = k;
                            break;
}}
                    if (nextUse == -1)
                    {
                        pos = j;
                        break;
                    }
                    if (nextUse > farthest)
                    {
                        farthest = nextUse;
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
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
