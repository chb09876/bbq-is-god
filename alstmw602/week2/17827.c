#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int m;
	int v;
	int tmp;
	int index;
	int num;
	int i;
	int *arr;
	
	scanf("%d %d %d", &n,&m,&v); 
	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		scanf("%d",&num);
		arr[i] = num;
		i++;
	}
	i = 0;
	while(i < m)
	{
		scanf("%d", &tmp);
		if (tmp < n)
			index = tmp;
		else
			index = ((tmp - n) % (n - v + 1)) + v - 1;
		printf("%d\n",arr[index]);
		i++;
	}
}
