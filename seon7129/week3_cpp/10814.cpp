#include <iostream>

using namespace std;

typedef struct person
{
    int age;
    char *name;
}person;

person p[1000001];
person temp[1000001];

void merge(int left, int mid, int right)
{
    int l, m, t;

    l = left;
    m = mid + 1;
    t = left;

    //정렬 후 합병
    while (l <= mid && m <= right)
    {
        if (p[l].age <= p[m].age)
        {
            temp[t++].age = p[l++].age;
            temp[t++].name = p[l++].name;
        }
        else
        {
            temp[t++].age = p[m++].age;
            temp[t++].name = p[m++].name;
        }
    }

    if (l > mid)
    {
        while(t <= right)
        {
            temp[t++].age = p[m++].age;
            temp[t++].name = p[m++].name;
        }
    }
    else
    {
        while(t <= mid)
        {
            temp[t++].age = p[l++].age;
            temp[t++].name = p[l++].name;
        }
    }

    //원래 배열로 복사
    while (left <= right)
    {
        p[left].age = temp[left].age;
        p[left].name = temp[left].name;
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
    int n;
    int i;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d %s", &p[i].age, p[i].name);

    merge_sort(0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d %s\n", p[i].age, p[i].name);

    return (0);
}