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

listNode *find_snail(listNode *h, int idx)
{
    listNode *snail;
    int i;

    snail = h;
    i = 0;
    while (i < idx)
    {
        snail = snail->next;
        i++;
    }
    return (snail);
}

listNode *read_node_idx(listNode *h, int num, int idx)
{
    int i;
    listNode *cur;

    cur = h;
    i = 0;
    while (i <= num)
    {
        if(cur->next == NULL)
        {
            cur->next = find_snail(h, idx);
        }
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

void print_node(listNode *h, int i, int idx)
{
    listNode *cur;
    cur = read_node_idx(h, i, idx);
    printf("%d\n", cur->data);
}

int main()
{
    int node_cnt;
    int que_cnt;
    int cycle_num;
    int i;
    listNode *h;
    int data;
    int que;

    h = init_list();
    scanf("%d %d %d", &node_cnt, &que_cnt, &cycle_num);
    i = 0;
    while (i < node_cnt)
    {
        scanf("%d", &data);
        add_last_node(h, data);
        i++;
    }

    i = 0;
    while (i < que_cnt)
    {
        scanf("%d", &que);
        print_node(h, que, cycle_num);
        i++;
    }

    delete_all_node(h);

    return (0);
}