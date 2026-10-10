#include <stdio.h>
int main()
{
    int n, totalFrames;
    int size[20];
    int framesPerProcess, remaining;
    int i;
    printf("========================================\n");
    printf("        EQUAL FRAME ALLOCATION\n");
    printf("========================================\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);
    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &size[i]);
    }
    framesPerProcess = totalFrames / n;
    remaining = totalFrames % n;
    printf("\nFrame Allocation:\n");
    printf("Process\tSize\tFrames\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\n", i + 1, size[i], framesPerProcess);
 }
    printf("\nRemaining Frames = %d\n", remaining);
    return 0;
}
