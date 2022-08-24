#include <stdio.h>

void cal_cnt(int num)
{
    int cnt;
    int n;
    n = num;
    cnt = 0;

    while (n != 0)
    {
        if (n >= 500)
        {
            cnt++;
            n -= 500;
        }
        else if (n >= 100)
        {
            cnt++;
            n -= 100;
        }
        else if (n >= 50)
        {
            cnt++;
            n -= 50;
        }
        else if (n >= 10)
        {
            cnt++;
            n -= 10;
        }
        else if (n >= 5)
        {
            cnt++;
            n -= 5;
        }
        else if (n >= 1)
        {
            cnt++;
            n -= 1;
        }
    }

    printf("%d", cnt);
}

int main()
{
    int n, num;
    scanf("%d", &n);
    num = 1000 - n;

    cal_cnt(num);

    return (0);
}