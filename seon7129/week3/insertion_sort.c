//마찬가지로 백준 문제는 시간 초과
#include <stdio.h>

void insertion_sort(int *arr, int n)
{
    int i;
    int j;
    int num;

    i = 1;
    j = 0;
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
    insertion_sort(arr, n);
    i = 0;
    while (i < n)
    {
        printf("%d\n", arr[i]);
        i++;
    }

    return (0);
}