#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    int count;
    Node *top;
} Stack;

void push(Stack *stack, int data)
{
    // 새로운 노드 만들기
    Node *newNode = (Node*)malloc(sizeof(Node));
    // 새로운 노드에 데이터 넣기
    newNode->data = data;
    // 새로운 노드에 탑 사이즈 만들기
    newNode->next = stack->top;

    // 새 노드를 탑 노드로 만들기
    stack->top = newNode;
    // 스택 사이즈 늘리기
    stack->count++;
}

int pop(Stack *stack)
{
    // 스택 카운트가 0이면 -1리컨
    if(stack->count == 0) {
        return -1;
    } 
    else // 스택에 자료가 있으면
    {
        // 탑에 있는 값을 노드에 담기
        Node *node = stack->top;
        // 노드의 값을 임시 변수에 담기
        int data = node->data;
        // 스택의 탑을 노드의 다음 데이터를 가르키키
        stack->top = node->next;
        // 노드 해제
        free(node);
        // 스택 카운트 마이너스
        stack->count--;
        return data;
    }
}

int isEmpty(Stack *stack)
{
    if(stack->count == 0)
        return 1;
    else
        return 0;
}

int top(Stack *stack)
{
    if(stack->count == 0)
        return -1;
    else
        return stack->top->data;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    Stack s;
    s.top == NULL;
    s.count = 0;

    for(int i = 0; i < N; i++) {
        char oper[6];
        scanf("%s", oper);
        if(strcmp(oper, "push") == 0)
        {
            int data;
            scanf("%d", &data);
            push(&s, data);
        }
        else if(strcmp(oper, "pop") == 0)
        {
            int data = pop(&s);
            printf("%d\n", data);
        }
        else if(strcmp(oper, "size") == 0)
        {
            printf("%d\n", s.count);
        } 
        else if(strcmp(oper, "empty") == 0)
        {
            int data = isEmpty(&s);
            printf("%d\n", data);
        }
        else
        {
            int data = top(&s);
            printf("%d\n", data);
        }
    }

    return 0;
}