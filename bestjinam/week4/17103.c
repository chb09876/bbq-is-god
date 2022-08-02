#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool not_prime[1000001];

int	main(void)
{
	int	m;
	int	*num;
	int	max, cnt;

	scanf("%d",&m);
	num = malloc(sizeof(int) * (m));
	max = 0;
	for (int i = 0; i < m; i ++)
	{
		scanf("%d", &num[i]);
		if (max < num[i]) max = num[i];
	}
	for (int i = 2; i < max; i ++)
	{
		if (not_prime[i] == false)
		{
			for (int k = i + i; k <= max; k += i)
			{
				not_prime[k] = true;
			}
		}
	}
	for (int i = 0; i < m; i ++)
	{
		cnt = 0;
		for (int j = 2; j <= num[i] - j; j ++)
		{
			if (!not_prime[j] && !not_prime[num[i] - j])
				cnt ++;
		}
		printf("%d\n", cnt);
	}
	free(num);

}
