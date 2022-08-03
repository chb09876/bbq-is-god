#include <stdio.h>
#include <math.h>

int num_len(int num)
{
    int i;

    i = 1;
    while (num > 9)
    {
        num = num / 10;
        i++;
    }

    return (i);
}

int check_p(int num)
{
    int len;
    len = num_len(num);
    int temp, i;
    int low = 0;
    int high = len - 1;
    int arr[len];
    temp = num;

    i = 0;
    while (temp)
    {
        arr[i] = temp % 10;
        temp /= 10;
        i++;
    }
    for (int j = 0; j < len/2; j++)
    {
        if (arr[low] != arr[high])
        {
            return (0);
        }
        low++;
        high--;
    }
    return (1);
}

int main()
{
    int num, j;
    int flag = 0;

    scanf("%d", &num);
    if (num <= 2)
        printf("2\n");
    else
    {
        while (num < 2147483647)
        {
            j = 2;
            while (j <= sqrt(num))
            {
                if (num % j == 0)
                {
                    flag = 1;
                    break;
                }
                j++;
            }
            if (flag == 0 && check_p(num) == 1)
            {
                printf("%d\n", num);
                break;
            }
            flag = 0;
            num++;
        }
    }

    return (0);
}