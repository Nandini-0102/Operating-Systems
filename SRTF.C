#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[100], visited[100];
    int n, head, i, j;
    int seek = 0, distance, min, index;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++)
    {
        min = 9999;
        index = -1;

        // Find the closest unvisited request
        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0)
            {
                distance = abs(head - request[j]);

                if(distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
        }

        // Move the head
        visited[index] = 1;
        seek = seek + min;
        head = request[index];

        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d cylinders\n", seek);

    return 0;
}
