#include <stdio.h>
#include <stdlib.h>

void qSort(int arr[], int l, int r)
{
	int left = l,right = r;
	int pivot = arr[(l + r)/2];
	int temp;
	do
	{
		while(arr[left]<pivot)
			left++;
		while(arr[right]>pivot)
			right--;
		if(left<=right)
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
			left++;
			right--;
		}
	}while(left<=right);

	if(l<right)
		qSort(arr,l,right);
	if(left<r)
		qSort(arr,left,r);
}

int main()
{
	int	n;
	int	*arr;
	int num;
	int temp;
	int i;
	int j;
	int min;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while(i < n)
	{
		scanf("%d", &num);
		arr[i] = num;
		i++;
	}
	qSort(arr,0,n - 1);
	i = 0;
	while(i < n)
	{
		printf("%d\n",arr[i]);
		i++;
	}
}
