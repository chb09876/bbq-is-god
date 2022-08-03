#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return (b);

    return (gcd(b, a%b));
}

long long cal(int *arr, int j)
{
    long long result = 0;

    for (int i = 0; i < j - 1; i++)
    {
        for (int k = i + 1; k < j; k++)
            result += gcd(arr[i], arr[k]);
    }

    return (result);
}

int main()
{
    int n, m, i, j;
    long long cnt;

    scanf("%d", &n);
    i = 0;
    while (i < n)
    {
        scanf("%d", &m);
        int arr[m];
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[j]);
        }
        cnt = cal(arr, m);
        cout << cnt << endl;
        i++;
    }

    return (0);
}