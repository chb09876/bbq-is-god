#include <stdio.h>

// TODO: 입력 정수값 조건 검사, 중복 검사 

int main(void)
{
    // int array[] = {5, 9, 4, 3, 2, 7};
    int lines, i;
    scanf("%d", &lines);
    int array[lines];
    int array_size = sizeof(array) / sizeof(int);

    for (i = 0; i < array_size; i++)
    {
        scanf("%d", &array[i]);
    }

    // printf("---\n");
    // for (i = 0; i < array_size; i++)
    // {   
    //     printf("%d\n", array[i]);
    // }
    int j, min;
    for (i = 0; i < array_size - 1; i++)
    // 안의 for문에서 i + 1을 하기 때문에 배열 범위를 넘어가지 않기 위해서 array_size - 1을 해준 것
    {
        min = i;
        for (j = i + 1; j < array_size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }

        int temp;
        temp  = array[i];
        array[i] = array[min];
        array[min] = temp;
    }

    for (i = 0; i < array_size; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}