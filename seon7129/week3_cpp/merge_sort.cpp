//메모리 초과난다.. 퀵소트로 풀어야겟다..
#include <iostream>

using namespace std;

int temp[1000000];
int *arr;

void merge(int left, int mid, int right)
{
    int l, m, t;

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
        while(t <= right)
            temp[t++] = arr[m++];
    }
    else
    {
        while(t <= mid)
            temp[t++] = arr[l++];
    }

    //원래 배열로 복사
    while (left <= right)
    {
        arr[left] = temp[left];
        left++;
    }
}

void merge_sort(int left, int right)
{
    int mid;

    if (left >= right)
        return ;

    mid = left + (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid ,right);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    int i;

    cin >> n;
    arr = new int[n];
    i = 0;
    while(i < n)
    {
        cin >> arr[i];
        i++;
    }
    merge_sort(0, n - 1);

    i = 0;
    while (i < n)
    {
        cout << arr[i] << "\n";
        i++;
    }

    return (0);
}