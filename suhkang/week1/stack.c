#include<stdio.h>
#include<stdlib.h>

// 노드 선언
struct node
{
    int data;
    struct node *next;
};

// 헤드 전역
struct node *head = NULL;

void push(int val)
{
    // 새로운 노드 만들기
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

    // 새로운 노드는 포인터기 헤드 노드를 가리키도록 함
    newNode->next = head;

    // 새 노드를 헤드 노드로 만듬
    // 헤드가 항상 마지막으로 삽입된 데이터를 가리키도록
    head = newNode;
}

void pop()
{
    //temp는 헤드 노드를 해제하는데 사용 됨.
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);

        // 헤드 노드 백업
        temp = head;

        // 헤드 노드가 다음 노드를 가리키도록 함
        // 논리적으로 노드 제거
        head = head->next;

        // 팝으로 제거된 요소의 메모리를 해제
        free(temp);
    }
}

// 연결 리스트 출력
void printList()
{
    struct node *temp = head;

    // 전체 연결 목록 반복 데이터 출력
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Linked List\n");
    printList();
    pop();
    printf("팝 이후에 새로운 연결 리스트\n");
    printList();
    pop();
    printf("팝 이후에 새로운 연결 리스트\n");
    printList();

    return (0);
}