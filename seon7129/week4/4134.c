#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int n, num, i, j;
    int flag = 0;

    scanf("%u", &n);
    i = 0;
    while (i < n)
    {
        scanf("%u", &num);
        if (num <= 2)
            printf("2\n");
        else
        {
            while (num < 4294967295)
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
                if (flag == 0)
                {
                    printf("%u\n", num);
                    break;
                }
                flag = 0;
                num++;
            }
        }
        i++;
    }

    return (0);
}