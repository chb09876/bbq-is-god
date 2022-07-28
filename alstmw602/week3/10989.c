#include <stdio.h>

int main()
{
	int	arr[10001] = {0};
	int	n;
	int num;
	int i;

	scanf("%d",&n);
	i = 0;
	while (i < n)
	{
		scanf("%d",&num);
		arr[num]++;
		i++;
	}
	i = 0;
	while (i < 10001)
	{
		while (arr[i] != 0)
		{
			printf("%d\n", i);
			arr[i]--;
		}
		i++;
	}
}
