#include <stdio.h>

int is_pn(int n)
{
	int i;

	i = 2;
	while (i*i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main()
{
	int n;
	int m;

	scanf("%d",&n);
	scanf("%d",&m);
	if(n ==1)
		n = 2;
	while (n < m + 1)
	{
		if(is_pn(n))
			printf("%d\n",n);
		n++;
	}
}
