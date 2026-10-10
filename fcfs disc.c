#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head;
    int request[100];
    int totalSeekTime = 0;

    // Number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    // Enter disk requests
    printf("Enter the disk request queue:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    // Initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Scheduling Order:\n");

    // Calculate seek time
    for(i = 0; i < n; i++)
    {
        int seekTime = abs(head - request[i]);

        printf("%d -> %d  (Seek Time = %d)\n",
               head, request[i], seekTime);

        totalSeekTime = totalSeekTime + seekTime;

        // Move head to current request
        head = request[i];
    }

    printf("\nTotal Seek Time = %d cylinders\n", totalSeekTime);

    return 0;
}
