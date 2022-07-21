//얘도 시간초과남... 왜...? 도대체 왜..?

#include <stdio.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[10];
int n;

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];

    do
    {
        do
            low++;
        while (list[low] < pivot);
        do
            high--;
        while (list[high] > pivot);
        if (low < high) SWAP (list[low], list[high], temp);
    } while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort (int list[], int left, int right)
{
    if (left < right)
    {
        int q;
        q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1 , right);
    }
}


int main()
{
    int n;
    int i;
    int num;

    scanf("%d", &n);
    i = 0;
    while(i < n)
    {
        scanf("%d", &num);
        arr[i] = num;
        i++;
    }
    quick_sort(arr, 0, n - 1);

    i = 0;
    while (i < n)
    {
        printf("%d\n", arr[i]);
        i++;
    }

    return (0);
}