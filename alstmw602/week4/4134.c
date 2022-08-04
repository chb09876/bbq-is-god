#include <stdio.h>
#include <stdlib.h>

int is_pn(int n)
{
	int i;

	i = 2;
	if (n == 1)
		return (0);
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
	int *arr;
	int num;
	int i;

	scanf("%d",&n);

	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		scanf("%d",&num);
		arr[i] = num;
		i++;
	}
	i = 0;
	while (i < n)
	{
		while (1)
		{
			if (is_pn(arr[i]))
				break;
			arr[i]++;
		}
		printf("%d\n",arr[i]);
		i++;
	}
}
