#include <stdio.h>
#include <string.h>

void Power(char *str, int n)
{
    long double data = 1.0;
    int i, size;

    for (i = 0; i < n; i++)
        data *= 2;

    sprintf(str, "%.0Lf", data);
    size = strlen(str);
    str[size - 1] = (char)(((int)(str[size - 1] - 48) - 1) + 48);
    printf("%s\n", str);
}

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
    char arr[100];

    scanf("%d", &n);

    Power(arr, n);

    if (n <= 20)
        hanoi(n, 1, 2, 3);

    return(0);
}