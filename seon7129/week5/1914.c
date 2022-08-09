#include <stdio.h>
#include <math.h>

void hanoi(int n, int start, int mid, int end)
{
    if (n == 1)
        printf("%d %d\n", start, end);
    else
    {
        hanoi(n - 1, start, end, mid);
        printf("%d %d\n", start, end);
        hanoi(n - 1, mid, start, end);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%.0f\n", pow(2, n) - 1);

    if (n <= 20)
        hanoi(n, 1, 2, 3);

    return(0);
}