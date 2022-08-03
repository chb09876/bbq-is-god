#include <stdio.h>

int main()
{
    int n, k;
    int arr[1001] = {0};
    int i, j, p;

    scanf("%d %d", &n, &k);
    i = 0;
    j = 0;
    p = 2;
    while (i != k)
    {
        j += p;
        if (j <= n && arr[j] == 0)
        {
            arr[j]++;
            i++;
        }
        else if (j > n)
        {
            for (int h = 3; h <= n; h++)
            {
                if (arr[h] == 0)
                {
                    j = 0;
                    p = h;
                    break;
                }
            }
        }
    }
    printf("%d", j);

    return (0);
}