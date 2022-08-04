#include <stdio.h>

int main()
{
	int a;
	int b;
	int i;

	i = 0;
	scanf("%d",&a);
	scanf("%d",&b);
	if (a > b)
	{
		if (a % b == 0)
		{
			while(i++ < b)
				printf("1");
		}
		else
			printf("1");
		printf("\n");
	}
	else
	{
		if (b % a == 0)
		{
			while( i++ < a )
				printf("1");
		}
		else
			printf("1");
		printf("\n");
	}
}
