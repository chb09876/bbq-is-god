/*
동적 메모리할당과 구조체를 이용해서 스택과 큐 구현하기
스택(큐)에 원소 **추가**, **삭제** 하는 기능이 있어야 함
스택(큐)에 할당된 메모리 이상으로 원소가 추가 될 때 메모리 확장도 구현해야함
메모리 할당 해제도 구현해야 함
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

Queue * front = NULL;
Queue * back = NULL;
 
void Push(int data)
{
    Queue * temp = (Queue*)malloc(sizeof(Queue));

    temp->data = data;
    temp->next = NULL;

    // 맨 처음 push
    if (front == NULL && back == NULL)
    {
        front = temp;
        back = temp;
        return;
    }

    // 맨 처음이 아니라면
    temp->next = back;
    back = temp;

    return;
}

int Pop()
{
    // 아무것도 없을 때
    if (front == NULL && back == NULL) return -1;

    int ret_data = front->data;

    // Queue안에 데이터가 1개 있을 때
    if (front == back)
    {
        front = back = NULL;
        return ret_data;
    }

    // 여러 개 있을 때
    Queue * temp = NULL;

    temp = back;

    while (temp->next != front)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    front = temp;

    return ret_data;
}
 
int Size()
{
    // 아무것도 없을 때
    if (front == NULL && back == NULL) return 0;

    // 1개 있을 때
    if (front == back) return 1;

    // 여러 개 있을 때

    int ret = 0;

    Queue * temp = NULL;

    temp = back;

    while (temp)
    {
        temp = temp->next;
        ++ret;
    }

    return ret;
}
 
int Empty()
{
    if (front == NULL && back == NULL) return 1;
    else return 0;
}
 
int Front()
{
    if (front == NULL && back == NULL) return -1;

    int ret = 0;
    ret = front->data;

    return ret;
}
 
int Back()
{
    if (front == NULL && back == NULL) return -1;

    int ret = 0;
    ret = back->data;

    return ret;
}
 
int main(void)
{
    char input[10];
    int input_number = 0, N = 0;
 
    scanf("%d", &N);
 
    while (N--)
    {
        scanf("%s", input);
 
        if (strcmp(input, "push") == 0)
        {
            scanf("%d", &input_number);
 
            Push(input_number);
        }
        else if (strcmp(input, "pop") == 0)
        {
            printf("%d\n", Pop());
        }
        else if (strcmp(input, "size") == 0)
        {
            printf("%d\n", Size());
        }
        else if (strcmp(input, "empty") == 0)
        {
            printf("%d\n", Empty());
        }
        else if (strcmp(input, "front") == 0)
        {
            printf("%d\n", Front());
        }
        else if (strcmp(input, "back") == 0)
        {
            printf("%d\n", Back());
        }
    }
 
    return 0;
}