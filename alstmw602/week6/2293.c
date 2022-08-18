#include <stdio.h>

int main()
{
	int	n;
	int	k;
	int	coin[101];
	int	value[100001];
	int	i;
	int	j;

	scanf("%d %d", &n, &k);
	i = 1;
	while (i <= n)
	{
		scanf("%d", &coin[i]);
		i++;
	}
	value[0] = 1;
	i = 1;
	while (i <= n)
	{
		j = coin[i];
		while (j <= k)
		{
			value[j] += value[j - coin[i]];
			j++;
		}
		i++;
	}
	printf("%d",value[k]);
}
