//계수정렬(counting sort) 공부하기
#include <iostream>

using namespace std;

int main()
{
    int arr[10001] = {0};

    int n, i, num;
    scanf("%d", &n);

    i = 0;
    while (i < n)
    {
        scanf("%d", &num);
        arr[num]++;
        i++;
    }

    i = 0;
    while (i < 10001)
    {
        while (arr[i])
        {
            printf("%d\n", i);
            arr[i]--;
        }
        i++;
    }

    return (0);
}