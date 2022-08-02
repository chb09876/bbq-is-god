#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool	not_prime[480000001];

int	main(void)
{
	long long	m, n;
	long long	*res;
	long long	max;
	long long	tmp;

	scanf("%lld", &m);
	res = malloc(sizeof(long long) * m);
	max = 0;
	for (long long i = 0; i < m; i ++)
	{
		scanf("%lld", &res[i]);
		if (res[i] > max)
			max = res[i];
	}
	if (max >= 25)
		max += max / 5;
	else
		max = 25;
	for (long long i = 2; i < max; i ++)
	{
		if (not_prime[i] == false)
		{
			for (long long j = i + i; j <= max; j += i)
			{
				not_prime[j] = true;
			}
		}
	}
	for (long long i = 0; i < m; i ++)
	{
		tmp = res[i];
		while (not_prime[tmp] == true)
			tmp ++;
		printf("%lld\n", tmp);
	}
	return (0);
}
