#include <stdio.h>

typedef struct Pair
{
    int first;
    int second;
} Pair;

Pair fibo_count[41];
int is_init[41];

Pair fibo(int N)
{
    if (!is_init[N])
    {
        Pair p_1 = fibo(N - 1);
        Pair p_2 = fibo(N - 2);
        fibo_count[N].first = p_1.first + p_2.first;
        fibo_count[N].second = p_1.second + p_2.second;
        is_init[N] = 1;
    }
    return fibo_count[N];
}

int main()
{
    fibo_count[0].first = 1;
    fibo_count[0].second = 0;
    is_init[0] = 1;
    fibo_count[1].first = 0;
    fibo_count[1].second = 1;
    is_init[1] = 1;

    int T;
    scanf("%d", &T);
    while (T)
    {
        int N;
        scanf("%d", &N);
        Pair p = fibo(N);
        printf("%d %d\n", p.first, p.second);
        --T;
    }
}