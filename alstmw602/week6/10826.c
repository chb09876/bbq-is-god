#include <stdio.h>
#include <stdlib.h>

int	get_digit(char *str)
{
	int cnt = 1;
	while (*str++)
		cnt++;
	return cnt;
}

char *add(char *a, char *b)
{
	int d;
	int ad;
	int bd;
	char *out;
	int c;

	ad = get_digit(a);
	bd = get_digit(b);

	if (ad > bd)
		d = ad + 2;
	else
		d = bd + 2;
	out = (char *)malloc(sizeof(char) * d);
	c = 0;
	out[d] = 0;
	d--;
	while (0 <= d && 0 <= ad && 0 <= bd)
	{
		if (a[ad] + b[bd] - '0' - '0' > 9)
		{
			out[d] = '0' + (a[ad] + b[bd] - '0' - '0' - 10);
			c = 1;
		}
		else
		{
			out[d] = '0' + (a[ad] + b[bd] - '0' - '0');
			c = 0;
		}
		d--;
		ad--;
		bd--;
	}
	if (c == 1)

	return out;
}

int main()
{
	int		i;
	int		n;
	char	*fib[10000];

	scanf("%d",&n);
	fib[0] = "0";
	fib[1] = "1";
	i = 1;
	while (i++ < 10001)
		fib[i] = add(fib[i - 2] , fib[i - 1]);
	printf("%s",fib[n]);
}
