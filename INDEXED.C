#include <stdio.h>
int main()
{	int index, n, i, blocks[20];
    printf("Enter index block: ");
    scanf("%d", &index);
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter the block numbers: ");
    for(i = 0; i < n; i++)
    {	scanf("%d", &blocks[i]);	}
    printf("\nIndex block: %d\n", index);
    printf("Allocated blocks are: ");
    for(i = 0; i < n; i++)
    {	printf("%d ", blocks[i]);  }
    printf("\n");
    return 0;	}
