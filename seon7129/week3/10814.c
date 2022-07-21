#include <stdio.h>

typedef struct person
{
    int age;
    char *name;
}person;

void bubble_sort(person *p, int n)
{
    char *temp_str = 0;
    int temp_num;
    int i, j;
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n - 1)
        {
            if (p[j].age > p[j + 1].age)
            {
                temp_num = p[j].age;
                p[j].age = p[j + 1].age;
                p[j + 1].age = temp_num;

                temp_str = p[j].name;
                p[j].name = p[j + 1].name;
                p[j + 1].name = temp_str;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    int n;
    int i;
    person p[100001];

    scanf("%d", &n);
    i = 0;
    while(i < n)
    {
        scanf("%d %s", &p[i].age, p[i].name);
        i++;
    }
    bubble_sort(p, n);
    i = 0;
    while (i < n)
    {
        printf("%d %s\n", p[i].age, p[i].name);
        i++;
    }

    return (0);
}