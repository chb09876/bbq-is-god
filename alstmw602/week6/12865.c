#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n;
	int	k;
	int	i;
	int j;
	int	v;
	int w;
	int **arr;

	arr = (int **)malloc(sizeof(int *) * 101);
	i = 0;
	while (i < 101)
	{
		arr[i] = (int*)malloc(1000001);
		i++;
	}
	scanf("%d %d", &n, &k);
	i = 1;
	while (i <= n)
	{
		j = 1;
		scanf("%d %d", &w, &v);
		while (j <= k)
		{
			if (j < w)
			{
				arr[i][j] = arr[i-1][j];
			}
			else
			{
				if (arr[i-1][j] >= arr[i - 1][j-w] + v)
					arr[i][j] = arr[i-1][j];
				else
					arr[i][j] = arr[i - 1][j - w] + v;
			}
			j++;
		}
		i++;
	}
	printf("%d", arr[n][k]);
}
