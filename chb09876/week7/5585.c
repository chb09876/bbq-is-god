#include <stdio.h>

int main()
{
    int bill;
    scanf("%d", &bill);
    int change = 1000 - bill;
    int count = 0;
    int n[] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 6; ++i)
    {
        while (change >= n[i])
        {
            ++count;
            change -= n[i];
        }
        if (change == 0)
            break;
    }
    printf("%d", count);
}