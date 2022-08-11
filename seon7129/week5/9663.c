#include <stdio.h>

int	abs(int num)
{
    if (num < 0)
        return ((-1) * num);
    else
        return (num);
}

int	promising(int *col, int i)
{
    int	k;

    k = 0;
    while (k < i)
    {
        if ((col[i] == col[k]) || (abs(col[i] - col[k]) == (i - k)))
            return (0);
        k++;
    }
    return (1);
}

void	queens(int *col, int i, int *cnt, int n)
{
    int	j;

    if (i == n)
    {
        *cnt = *cnt + 1;
        return ;
    }
    j = 0;
    while (j < n)
    {
        col[i] = j;
        if (promising(col, i))
            queens(col, i + 1, cnt, n);
        j++;
    }
}

int	main()
{
    int	col[15];
    int	cnt;
    int n;

    cnt = 0;
    scanf("%d", &n);
    queens(col, 0, &cnt, n);
    printf("%d", cnt);

    return (0);
}