#include <stdio.h>

/*
가장 먼저 나가는 사람을 먼저 배치... 욕심 그득
*/

int main()
{
    int p[1000];
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", p + i);
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - 1 - i; ++j)
        { // 주어진 입력의 개수가 1000개라 버블소트 사용. 만약 많은 입력이 있었으면 타임아웃을 생각해서 더 빠른 소트를 써야함.
            if (p[j] > p[j + 1])
            {
                int tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
    long long int result = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
            result = result + p[j];
    }
    printf("%lld", result);
}