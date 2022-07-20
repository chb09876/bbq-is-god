#include <stdio.h>

void    selection_sort(int arr[]) 
{
    int min, tmp;

    for (int i = 0; i < 5; i++)
    {
        min = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int arr[] = {9,6,7,3,5,4};

    selection_sort(arr);
    return (0);
}