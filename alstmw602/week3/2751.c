#include <stdio.h>

void merge(int arr[], int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = p;
	int tmp[1000000];

	while (i <= q && j <= r)
	{
		if(arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while(i <= q)
		tmp[k++] = arr[i++];
	while(j <= r)
		tmp[k++] = arr[j++];
	for(int a = p; a<=r; a++) arr[a] = tmp[a];
}

void mergeSort(int arr[], int p, int r)
{
	int q;

	if(p < r)
	{
		q = (p+r)/2;
		mergeSort(arr, p, q);
		mergeSort(arr, q+1 , r);
		merge(arr, p, q, r);
	}
}

int main()
{
	int	n;
	int	arr[1000000];
	int num;
	int temp;
	int i;
	int j;
	int min;

	scanf("%d", &n);
	i = 0;
	while(i < n)
	{
		scanf("%d", &num);
		arr[i] = num;
		i++;
	}
	mergeSort(arr,0,n - 1);
	i = 0;
	while(i < n)
	{
		printf("%d\n",arr[i]);
		i++;
	}
}
