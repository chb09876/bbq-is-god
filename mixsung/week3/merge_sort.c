#include <stdio.h>
int array[1000000];
int temp_array[1000000];

// 백준 2751번 문제 (수 정렬하기 2)
// O(nlogn) 시간복잡도를 가진 정렬 알고리즘을 사용해야 시간초과 X -> merge, heap, quick 중 선택
// 배열 크기를 지정하고 돌리면 시간이 너무 오래 걸린다.. 이 방법밖에 없나... 예외처리..불가능..?

void conquer_combine(int array[], int left, int mid, int right)
{
    // mid가 필요한 이유는 배열 요소 2개만 비교할 때만 하는게 아니라 요소 3개 4개 이상일 때를 위해서.
    int left_index, mid_next, array_index, i;
    left_index = left;
    mid_next = mid + 1;
    array_index = left;

    while (left_index <= mid && mid_next <= right)
    {
        if (array[left_index] <= array[mid_next])
            temp_array[array_index++] = array[left_index++];
        else
            temp_array[array_index++] = array[mid_next++];
    }

    // left_index > mid ==> mid_next가 덜 찼다는 의미. mid_next를 채워주기.
    if (left_index > mid)
    {
        for (i = mid_next; i <= right; i++)
            // 남은 임시 배열 요소에 남은 값 넣어주기
            temp_array[array_index++] = array[i];
    }
    else
    {
        for (i = left_index; i <= mid; i++)
            temp_array[array_index++] = array[i];
    }

    // 원래 배열에 임시배열 요소들을 넣어주기. 
    for (i = left; i <= right; i++)
        array[i] = temp_array[i];
}

void divide(int array[], int left, int right)
{
    int mid;

    if (left < right) // 분할을 위한 아주 중요한 조건
    {
        mid = (left + right) / 2;

        divide(array, left, mid);
        divide(array, mid + 1, right);
        conquer_combine(array, left, mid, right);        
    }
}

int main(void)
{
    int lines, i;
    scanf("%d", &lines);

    for (i = 0; i < lines; i++)
        scanf("%d", &array[i]);
    
    divide(array, 0, lines - 1);

    for (i = 0; i < lines; i++)
        printf("%d\n", array[i]);

    return (0);
}