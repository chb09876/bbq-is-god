#include <stdio.h>
#include <stdlib.h>

typedef struct schedule
{
    int start;
    int finish;
} schedule;

int cmp(const void *a, const void *b)
{
    if (((schedule *)a)->finish > ((schedule *)b)->finish)
        return 1;
    else if (((schedule *)a)->finish < ((schedule *)b)->finish)
        return -1;
    else if (((schedule *)a)->start > ((schedule *)b)->start)
        return 1;
    else if (((schedule *)a)->start < ((schedule *)b)->start)
        return -1;
    return 0;
}

int main()
{
    int N;
    scanf("%d", &N);
    schedule meetings[100000];
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &(meetings + i)->start, &(meetings + i)->finish);
    qsort(meetings, N, sizeof(schedule), cmp);
    int prev = -1;
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (prev <= (meetings + i)->start)
        {
            prev = (meetings + i)->finish;
            ++count;
        }
    }
    printf("%d", count);
}