// 10 이랑 15가 있으면 10*2=20 가장 작은 중량이 고르게 걸림
#include <stdio.h>

void insertion_sort(int *arr, int n)
{
    int i;
    int j;
    int num;

    i = 1;
    while (i < n)
    {
        num = arr[i];
        j = i - 1;
        while (j >= 0 && num < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = num;
        i++;
    }
}

void cal_weight(int *arr, int n)
{
    int max;
    int i, idx;
    int temp;
    i = n;
    idx = 0;
    max = 0;
    temp = 0;

    while (i != 0)
    {
        temp = arr[idx] * i;
        if (temp > max)
            max = temp;
        idx++;
        i--;
    }

    printf("%d", max);
}

int main()
{
    int n;
    int arr[100001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);
    cal_weight(arr, n);

    return (0);
}