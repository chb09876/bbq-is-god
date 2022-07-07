#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 불린 변수 선언
#define TRUE 1
#define FALSE 0
#define MINUS -1

// 구조체 선언
typedef struct _stack
{
    int top;
    int *data;
    int max;
}   Stack;

// 스택 초기화
void StackInit(Stack * sp, int size)
{
    sp->data = (int *) malloc(size * sizeof(int));
    if (!sp->data)
        return ;
    sp->top = -1;
    sp->max = size;
}

int IsEmpty(Stack * sp)
{
    if(sp->top == -1) return TRUE;
    return FALSE;
}

int Size(Stack *sp)
{
    return sp->top + 1;
}

int IsFull(Stack * sp)
{
    if(sp->top + 1 >= sp->max) return TRUE;
    return FALSE;
}

void Push(Stack * sp, int data) 
{
    if(IsFull(sp) == TRUE)
    {
        sp->data = (int *) realloc(sp->data, sp->max * 2 * sizeof(int));
        if (!sp->data) return ;
        Push(sp, data);
    }
    else
    {
        sp->top++;
        sp->data[sp->top] = data;
    }
}

int Pop(Stack * sp)
{
    if(IsEmpty(sp) == TRUE) return MINUS;
    return sp->data[(sp->top)--];
}

int Top(Stack *sp)
{
    if(IsEmpty(sp) == TRUE) return MINUS;
    return sp->data[sp->top];
}

int main(void)
{
    int     n;
    char    oper[6];
    int     i;
    int     num;
    Stack   stack;
    
    scanf("%d", &n);
    fgetc(stdin);
    StackInit(&stack, 1000);
    
    i = 0;
    while (i < n)
    {
        scanf("%s", oper);
        fgetc(stdin);

        if(strcmp(oper, "push") == 0)
        {
            scanf("%d", &num);
            fgetc(stdin);
            Push(&stack, num);
        }
        else if(strcmp(oper, "pop") == 0)
        {
            printf("%d\n", Pop(&stack));
        }
        else if(strcmp(oper, "empty") == 0)
        {
            printf("%d\n", IsEmpty(&stack));
        }
        else if(strcmp(oper, "size") == 0)
        {
            printf("%d\n", Size(&stack));
        }
        else if(strcmp(oper, "top") == 0)
        {
            printf("%d\n", Top(&stack));
        }

        i++;
    }

    return (0);
}
