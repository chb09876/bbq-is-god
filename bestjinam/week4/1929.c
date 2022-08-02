#include <stdio.h>
#include <stdbool.h>

bool non_prime[1000001];

int main(void)
{
    int    n, m;

    scanf("%d %d", &m, &n);
	non_prime[1] = true;
    for(int i = 2; i < n; i ++)
	{
		if (non_prime[i] == false)
		{
			for (int j = i + i ; j <= n; j += i)
				non_prime[j] = true;
		}
	}
    for(int i = m; i <= n; i ++)
	{
		if (non_prime[i] == false)
			printf("%d\n", i);
	}
	return (0);
}
