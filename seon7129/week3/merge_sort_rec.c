//SIGSEGV 허용되지 않은 메모리 액세스로 오류가 난다..
//내일 고칠래...
#include <stdio.h>

void merge(int *arr, int left, int right)
{
    int mid;
    int temp[10000000];
    int l, m, t;
    int i;

    mid = (left + right) / 2;
    l = left;
    m = mid + 1;
    t = left;

    //정렬 후 합병
    while (l <= mid && m <= right)
    {
        if (arr[l] <= arr[m])
            temp[t++] = arr[l++];
        else
            temp[t++] = arr[m++];
    }
    if (l > mid)
    {
        i = l;
        while(i <= right)
        {
            temp[t++] = arr[i];
            i++;
        }
    }
    else
    {
        i = l;
        while(i <= mid)
        {
            temp[t++] = arr[i];
            i++;
        }
    }

    //원래 배열로 복사
    i = left;
    while (i <= right)
    {
        arr[i] = temp[i];
        i++;
    }
}

void merge_sort(int *arr, int left, int right)
{
    int mid;

    if (left == right)
        return ;

    mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, right);
}

int main()
{
    int n;
    int arr[10000000];
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
    merge_sort(arr, 0, n - 1);

    i = 0;
    while (i < n)
    {
        printf("%d\n", arr[i]);
        i++;
    }

    return (0);
}