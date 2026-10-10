
#include <stdio.h>
int main(){
    int n, blocks[50], i;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &blocks[i]);}
    printf("\nLinked File Allocation:\n");
    for(i = 0; i < n; i++)		{
        if(i == n - 1)
            printf("%d -> NULL", blocks[i]);
        else
           printf("%d -> ", blocks[i]);	}
    return 0;}
