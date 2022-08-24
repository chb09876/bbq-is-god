//세그폴트....
#include <stdio.h>

struct node
{
    int right;
    int left;
}Node[26];

//전위순회 ABC
void preorder(int i)
{
    printf("%c", (char)(i + 'A'));
    if (Node[i].left != -1)
        preorder(Node[i].left);
    if (Node[i].right != -1)
        preorder(Node[i].right);
    return ;
}

//중위순회 DBA
void inorder(int i)
{
    if (Node[i].left != -1)
        inorder(Node[i].left);
    printf("%c", (char)(i + 'A'));
    if (Node[i].right != -1)
        inorder(Node[i].right);
    return ;
}

//후위순회 DBE
void postorder(int i)
{
    if (Node[i].left != -1)
        postorder(Node[i].left);
    if (Node[i].right != -1)
        postorder(Node[i].right);
    printf("%c", (char)(i + 'A'));
    return ;
}

int main()
{
    int n;
    int i;
    char a, b, c;

    for (i = 0; i < 26; i++)
    {
        Node[i].left = -1;
        Node[i].right = -1;
    }

    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        scanf("%c %c %c", &a, &b, &c);
        getchar();
        //fflush(stdin);
        if (b != '.')
            Node[a - 'A'].left = b - 'A';
        if (c != '.')
            Node[a - 'A'].right = c - 'A';
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);

    return (0);
}