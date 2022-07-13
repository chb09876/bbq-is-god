//하지만 여전히 타임에러가 났다고 한다.. 왜지;;
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    struct listNode *next;
    int data;
}listNode;

listNode *init_list()
{
    listNode *head;
    head = (listNode *)malloc(sizeof(listNode));
    head->next = NULL;

    return (head);
}

listNode *find_end(listNode *h)
{
    listNode *cur;
    cur = h;

    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return (cur);
}

int find_len(listNode *h)
{
    listNode *cur;
    int cnt;
    cnt = 0;
    cur = h;

    while (cur->next != NULL)
    {
        cur = cur->next;
        cnt++;
    }
    return (cnt);
}

listNode *read_node_idx(listNode *h, int num)
{
    int i;
    listNode *cur;

    cur = h;
    i = 0;
    while (i <= num)
    {
        cur = cur->next;
        i++;
    }
    return (cur);
}

void add_last_node(listNode *h, int data)
{
    listNode *end;
    end = find_end(h);
    listNode *newNode;
    newNode = (listNode *) malloc(sizeof(listNode));
    newNode->data = data;
    end->next = newNode;
    newNode->next = NULL;
}

void delete_all_node(listNode *h)
{
    listNode *cur;
    cur = h;

    listNode *nxt;
    while(cur != NULL)
    {
        nxt = cur->next;

        free(cur);
        cur = nxt;
    }
    free(h);
}

void print_node(listNode *h, int i)
{
    listNode *cur;

    cur = read_node_idx(h, i);
    printf("%d\n", cur->data);
}

int main()
{
    int node_cnt;
    int que_cnt;
    int cycle_num;
    int i;
    listNode *h1;
    listNode *h2;
    int data;
    int que;
    int len1;
    int len2;

    h1 = init_list();
    h2 = init_list();
    scanf("%d %d %d", &node_cnt, &que_cnt, &cycle_num);
    i = 1;
    while (i <= node_cnt)
    {
        scanf("%d", &data);
        if(i < cycle_num)
        {
            add_last_node(h1, data);
        }
        else
        {
            add_last_node(h2, data);
        }
        i++;
    }

    len1 = find_len(h1);
    len2 = find_len(h2);
    i = 0;
    while (i < que_cnt)
    {
        scanf("%d", &que);
        if(que < cycle_num - 1)
        {
            print_node(h1, que);
        }
        else
        {
            que = (que - len1) % len2;
            print_node(h2, que);
        }
        i++;
    }

    delete_all_node(h1);
    delete_all_node(h2);

    return (0);
}