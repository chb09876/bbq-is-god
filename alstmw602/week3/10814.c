#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct member
{
	short age;
	char *name;
};

void merge(struct member arr[], int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = p;
	struct member tmp[100000];

	while (i <= q && j <= r)
	{
		if(arr[i].age <= arr[j].age)
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

void mergeSort(struct member arr[], int p, int r)
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
	int		n;
	int		i;
	struct	member members[100000];
	char *name;
	short age;

	scanf("%d",&n);
	i = 0;
	while(i < n)
	{
		scanf("%hd",&age);
		members[i].age = age;
		name = (char *)malloc(sizeof(char)*100);
		scanf("%s",name);
		members[i].name = name;
		i++;
	}
	mergeSort(members,0,n-1);
	i = 0;
	while(i < n)
	{
		printf("%hd ",members[i].age);
		printf("%s\n",members[i].name);
		i++;
	}
}
