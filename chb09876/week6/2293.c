#include <stdio.h>

int get_comb(int k, int coin_numer, int *coins)
{
    if (k == 0)
        return 1;
    if (k < 0)
        return 0;
    int result = 0;
    for (int i = 0; i < coin_numer; ++i)
        result += get_comb(k - coins[i], coin_numer, coins);
    return result;
}

int main()
{
    int n, k;
    int coins[100];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        int v;
        scanf("%d", &v);
        coins[i] = v;
    }
    printf("%d", get_comb(k, n, coins));
}