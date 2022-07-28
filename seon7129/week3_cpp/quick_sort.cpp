#include <iostream>

using namespace std;

int arr[100000001];

void quick_sort(int left, int right)
{
    if(left >= right)
        return ;

    int pivot, low, high;
    //배열의 중앙부분을 pivot으로
    pivot = arr[(left + right) / 2];
    low = left;
    high = right;

    while (low <= high)
    {
        while (arr[low] < pivot)
            low++;
        while (arr[high] > pivot)
            high++;
        if (low <= high)
        {
            swap(arr[low], arr[high]);
            low++;
            high++;
        }
    }
    quick_sort(left, high);
    quick_sort(low, right);
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quick_sort(0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return (0);
}