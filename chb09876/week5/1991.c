#include <stdio.h>
#include <stdlib.h>

typedef struct Pair
{
    char first;
    char second;
} Pair;

void preorder_traversal(Pair *arr, char name);
void inorder_traversal(Pair *arr, char name);
void postorder_traversal(Pair *arr, char name);

int main()
{
    Pair arr[26];
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; ++i)
    {
        char p, l, r;
        scanf("%c %c %c", &p, &l, &r);
        getchar();
        arr[p - 'A'].first = l;
        arr[p - 'A'].second = r;
    }
    preorder_traversal(arr, 'A');
    printf("\n");
    inorder_traversal(arr, 'A');
    printf("\n");
    postorder_traversal(arr, 'A');
}

void preorder_traversal(Pair *arr, char name)
{
    printf("%c", name);
    if (arr[name - 'A'].first != '.')
        preorder_traversal(arr, arr[name - 'A'].first);
    if (arr[name - 'A'].second != '.')
        preorder_traversal(arr, arr[name - 'A'].second);
}
void inorder_traversal(Pair *arr, char name)
{
    if (arr[name - 'A'].first != '.')
        inorder_traversal(arr, arr[name - 'A'].first);
    printf("%c", name);
    if (arr[name - 'A'].second != '.')
        inorder_traversal(arr, arr[name - 'A'].second);
}
void postorder_traversal(Pair *arr, char name)
{
    if (arr[name - 'A'].first != '.')
        postorder_traversal(arr, arr[name - 'A'].first);
    if (arr[name - 'A'].second != '.')
        postorder_traversal(arr, arr[name - 'A'].second);
    printf("%c", name);
}