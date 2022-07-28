#include <iostream>

using namespace std;

typedef struct person
{
    int age;
    char *name;
}person;

person p[100001];
person temp[100001];

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
            temp[t++] = p[l++];
        else
            temp[t++] = p[m++];
    }

    if (l > mid)
    {
        while(m <= right)
            temp[t++] = p[m++];
    }
    else
    {
        while(l <= mid)
            temp[t++] = p[l++];
    }

    //원래 배열로 복사
    while (left <= right)
    {
        p[left] = temp[left];
        left++;
    }
}

void merge_sort(int left, int right)
{
    int mid;

    if (left >= right)
        return ;

    mid = (left + right) / 2;
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
    {
        scanf("%d", &p[i].age);
        scanf("%d", p[i].name);
    }

    merge_sort(0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i].age);
        printf("%s\n", p[i].name);
    }

    return (0);
}