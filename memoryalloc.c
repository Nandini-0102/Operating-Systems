#include <stdio.h>

void firstFit(int partitions[], int n, int processes[], int m)
{
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (partitions[j] >= processes[i])
            {
                allocation[i] = j;
                partitions[j] = -1;  // Partition is occupied
                break;
            }
        }
    }

    printf("\n--- First Fit ---\n");
    printf("Process\tSize\tPartition\n");

    for (int i = 0; i < m; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
}

void bestFit(int partitions[], int n, int processes[], int m)
{
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int best = -1;

        for (int j = 0; j < n; j++)
        {
            if (partitions[j] >= processes[i])
            {
                if (best == -1 || partitions[j] < partitions[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            partitions[best] = -1;
        }
    }

    printf("\n--- Best Fit ---\n");
    printf("Process\tSize\tPartition\n");

    for (int i = 0; i < m; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
}

void worstFit(int partitions[], int n, int processes[], int m)
{
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int worst = -1;

        for (int j = 0; j < n; j++)
        {
            if (partitions[j] >= processes[i])
            {
                if (worst == -1 || partitions[j] > partitions[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            partitions[worst] = -1;
        }
    }

    printf("\n--- Worst Fit ---\n");
    printf("Process\tSize\tPartition\n");

    for (int i = 0; i < m; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
}

int main()
{
    int n, m;

    printf("Enter number of partitions: ");
    scanf("%d", &n);

    int original[n];

    printf("Enter size of each partition:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Partition %d: ", i + 1);
        scanf("%d", &original[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &m);

    int processes[m];

    printf("Enter size of each process:\n");
    for (int i = 0; i < m; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    // First Fit
    int first[n];
    for (int i = 0; i < n; i++)
        first[i] = original[i];

    firstFit(first, n, processes, m);

    // Best Fit
    int best[n];
    for (int i = 0; i < n; i++)
        best[i] = original[i];

    bestFit(best, n, processes, m);

    // Worst Fit
    int worst[n];
    for (int i = 0; i < n; i++)
        worst[i] = original[i];

    worstFit(worst, n, processes, m);

    return 0;
}
