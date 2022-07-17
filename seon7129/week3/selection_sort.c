//2751에서 타임에러남. 시간 복잡도 낮은 정렬 알고리즘으로 해결해야될 듯
#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void selection_sort(int *arr, int n)
{
    int i;
    int j;
    int min;

    i = 0;
    while (i < n)
    {
        min = i;
        j = i + 1;
        while (j < n)
        {
            if (arr[min] > arr[j])
                min = j;
            j++;
        }
        if (min != i)
            ft_swap(&arr[i], &arr[min]);
        i++;
    }
}

int main()
{
    int n;
    int arr[1000000];
    int i;
    int num;

    scanf("%d", &n);
    i = 0;
    while(i < n)
    {
        scanf("%d", &num);
        arr[i] = num;
        i++;
    }
    selection_sort(arr, n);

    i = 0;
    while (i < n)
    {
        printf("%d\n", arr[i]);
        i++;
    }

    return (0);
}