#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, head, temp;
    int request[100];
    int total = 0;
    int pos;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sort the requests
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    // Find first request greater than or equal to head
    pos = 0;
    while(pos < n && request[pos] < head)
        pos++;

    printf("\nC-LOOK Order: %d", head);

    // Move towards higher cylinders
    for(i = pos; i < n; i++)
    {
        total += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    // Jump to the lowest request
    if(pos > 0)
    {
        total += abs(head - request[0]);
        head = request[0];
        printf(" -> %d", head);

        // Continue in the same direction
        for(i = 1; i < pos; i++)
        {
            total += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d cylinders\n", total);

    return 0;
}
