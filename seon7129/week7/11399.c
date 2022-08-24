//정렬 후 a*n + b*(n-1) + .. 해서 계산?
#include <stdio.h>

void cal_time(int *arr, int n)
{
    int result;
    int cnt;
    int i;
    result = 0;
    cnt = n;

    i = 1;
    while (i < 1001 && n > 0)
    {
        if (arr[i] == 0)
            i++;
        else
        {
            result = result + (i * cnt);
            arr[i]--;
            cnt--;
        }
    }

    printf("%d", result);
}

int main()
{
    int n, num;
    int arr[1001] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr[num]++;
    }
    cal_time(arr, n);

    return (0);
}

