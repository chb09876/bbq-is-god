#include <stdio.h>
#include <math.h>

int main()
{
    int m, n;
    int i;
    int j;
    int flag = 0;

    scanf("%d", &m);
    scanf("%d", &n);

    i = m;
    if (i < 2)
        i = 2;
    while (i <= n)
    {
        j = 2;
        while (j <= sqrt(i))
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
            j++;
        }
        if(flag == 0)
            printf("%d\n", i);
        flag = 0;
        i++;
    }

    return (0);
}