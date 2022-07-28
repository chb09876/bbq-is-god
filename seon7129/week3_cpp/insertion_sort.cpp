#include <iostream>

using namespace std;

void insertion_sort(int *arr, int n)
{
    int i;
    int j;
    int num;

    i = 1;
    while (i < n)
    {
        num = arr[i];
        j = i - 1;
        while (j >= 0 && num < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = num;
        i++;
    }
}


int main()
{
    int n;
    int arr[1000000];
    int i;
    int num;

    cin >> n;
    i = 0;
    while(i < n)
    {
        cin >> num;
        arr[i] = num;
        i++;
    }
    insertion_sort(arr, n);
    i = 0;
    while (i < n)
    {
        cout << arr[i] << endl;
        i++;
    }

    return (0);
}