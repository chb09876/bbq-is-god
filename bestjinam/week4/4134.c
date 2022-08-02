#include <stdio.h>
#include <stdlib.h>

int	ft_isprime(long long nb)
{
	long long	i;

	if (nb < 2)
		return (0);
	else if (nb == 2)
		return (1);
	i = 3;
	if (nb % 2 == 0)
		return (0);
	while (i  <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
}

long long	ft_find_next_prime(long long nb)
{
	if (nb <= 2)
		return (2);
	else if (ft_isprime(nb) == 1)
		return (nb);
	return (ft_find_next_prime(nb + 1));
}

int main(void)
{
	int  m;
	long long *num;

	scanf("%d", &m);
	num = malloc(sizeof(long long) * m);
	for (int i = 0; i < m; i ++)
		scanf("%lld", &num[i]);
	for (int i = 0; i < m; i ++)
		printf("%lld\n", ft_find_next_prime(num[i]));
	free(num);
	return (0);
}
