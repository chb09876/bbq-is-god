// Fixed version of counting algorithm. (time out)
// Baekjoon 10989 
#include <stdio.h>

int array[10001];

int main(void)
{
    int lines;
    scanf("%d", &lines);

    // input with range of lines -> array index++
    while (lines != 0)
    {
        int num;
        scanf("%d", &num);
        array[num]++;
        lines--;
    }
    
    for (int i = 0; i < 10001; i++)
    {
        while (array[i] > 0)
        {
            printf("%d\n", i);
            array[i]--;
        }
    }

    return (0);
}