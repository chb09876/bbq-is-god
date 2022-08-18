#include <stdio.h>

int main()
{
	int	w;
	int	c;
	int i;
	int tmp;

	scanf("%d",&w);
	i = 0;
	while (i < 5)
	{
		tmp = (w - (i * 3));
		if (tmp < 0)
		{
			i = 5;
			break;
		}
		if(tmp % 5 == 0)
		{
			c = tmp / 5 + i;
			break;
		}
		i++;
	}
	if (i == 5)
		printf("-1");
	else
		printf("%d",c);
}
