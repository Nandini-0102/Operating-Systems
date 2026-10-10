#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i, head, diskSize;
    int request[100];
    int totalSeek = 0;
    int current;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    sort(request, n);

    current = head;

    printf("\nC-SCAN Scheduling Order:\n");

    // Service requests greater than head
    for(i = 0; i < n; i++)
    {
        if(request[i] >= head)
        {
            printf("%d -> %d\n", current, request[i]);
            totalSeek += abs(current - request[i]);
            current = request[i];
        }
    }

    // Move to end of disk
    printf("%d -> %d\n", current, diskSize - 1);
    totalSeek += abs(current - (diskSize - 1));
    current = diskSize - 1;

    // Jump to beginning
    printf("%d -> 0\n", current);
    totalSeek += diskSize - 1;
    current = 0;

    // Service remaining requests
    for(i = 0; i < n; i++)
    {
        if(request[i] < head)
        {
            printf("%d -> %d\n", current, request[i]);
            totalSeek += abs(current - request[i]);
            current = request[i];
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}
