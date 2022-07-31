#include <stdio.h>

int array[100000000];
int temp[100000000] = {0,};

// 백준 10989번 문제 (수 정렬하기 3) 첫 풀이 (시간초과로 실패)

void counting_sort(int arr[], int lines, int max)
{
    int index, t, i;
    
    for (index = 0; index < lines; index++)
    {
        t = arr[index];
        temp[t]++;
    }

    for (index = 0; index <= max; index++)
    {
        if (temp[index] != 0)
        {
            for (i = 0; i < temp[index]; i++)
                printf("%d\n", index);
        }
    }
}

int main(void)
{
    int lines, i;
    scanf("%d", &lines);

    for (i = 0; i < lines; i++)
    {
        scanf("%d", &array[i]);
    }

    int max;
    max = array[0];

    for (i = 0; i < lines; i++)
    {
        if (array[i] > max)
            max = array[i]; 
    }

    counting_sort(array, lines, max);

    return (0);
}