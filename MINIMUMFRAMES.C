#include <stdio.h>
int main()
{
    int n, totalFrames;
    int minFrames[20];
    int i, required = 0;
    printf("========================================\n");
    printf("      MINIMUM FRAME ALLOCATION\n");
    printf("========================================\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);
    printf("Enter minimum frames required by each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &minFrames[i]);
        required += minFrames[i];
    }
    printf("\nFrame Allocation:\n");
    if (required <= totalFrames)
    {
        for (i = 0; i < n; i++)
        {
            printf("Process %d -> %d frames\n",
                   i + 1, minFrames[i]);
        }
        printf("\nUnused Frames = %d\n",
               totalFrames - required);
    }
    else
    {
        printf("\nMinimum frame requirement cannot be satisfied.\n");
    }
    return 0;
}
