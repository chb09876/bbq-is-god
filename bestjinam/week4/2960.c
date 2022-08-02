#include <stdio.h>
#include <stdbool.h>

bool rm_chk[1001];

int main(void)
{
    int    n, k;
	int	   cnt = 0;

    scanf("%d %d", &n, &k);
    for(int i = 2; i <= n; i ++)
	{
		if (rm_chk[i] == false)
		{
			for (int j = i; j <= n; j += i)
			{
				if (rm_chk[j] == true) continue ;
				rm_chk[j] = true;
				cnt ++;
				if (cnt == k)
				{
					printf("%d\n", j);
					goto end ;
				}
			}
		}
	}
end:
	return (0);
}
