// 2와 9가 연결된 링크드리스트를 만들고, 받은 입력에 따라 저장된 값을 출력
#include <stdio.h>

int main()
{
	int n, m, v, i, j, num;
	int arr[200001] = {0, };

	scanf("%d %d %d", &n, &m, &v);
	i = 0;
	while (i < n)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	while (m--)
	{
		scanf("%d", &num);
		if (num < n)
			printf("%d\n", arr[num + 1]);
		else
			printf("%d\n", arr[(num - n) % (n - v + 1) + v]);
	}
	return (0);
}