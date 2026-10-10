
#include <stdio.h>
int main()
{    int start, length, i;
    printf("Enter starting block: ");
    scanf("%d", &start);
    printf("Enter number of blocks: ");
    scanf("%d", &length);
    printf("Allocated blocks are: ");
    for(i = start; i < start + length; i++)
    {	printf("%d ", i);	}
    printf("\n");
    return 0;	}
