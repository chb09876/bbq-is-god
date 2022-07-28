#include <iostream>

using namespace std;

template<typename T>
void Swap(T &a, T &b)
{
    T temp;
    temp = b;
    b = a;
    a = temp;
}

void selection_sort(int *arr, int n)
{
    int i, j, min;

    i = 0;
    while (i < n)
    {
        min = i;
        j = i + 1;
        while (j < n)
        {
            if (arr[min] > arr[j])
                min = j;
            j++;
        }
        if (min != i)
            Swap(arr[i], arr[min]);
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
    selection_sort(arr, n);

    i = 0;
    while (i < n)
    {
        cout << arr[i] << endl;
        i++;
    }

    return (0);
}