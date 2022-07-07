#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// 원형 큐를 위한 구조체 선언
typedef struct _queue
{
    int front;
    int rear;
    int *data;
    int max;
    int size;
}Queue;

int Pop(Queue *pq);

void InitQueue(Queue * pq, int size)
{
    // main 실행 시 매개변수로 전달받은 임의의 size 크기 만큼 동적할당해준다.
    pq->data = (int *) malloc(size * sizeof(int));
    // data에 값이 없으면 리턴 처리
    if (!pq->data)
        return ;
    // 초기화에서는 앞과 뒤 인덱스를 동일하게 맞춰준다.
    pq->front = size - 1;
    pq->rear = size - 1;
    // 큐의 최대값
    pq->max = size;
    // 큐의 크기
    pq->size = 0;
}

int Empty(Queue * pq)
{
    // 큐에 값이 없는 것은 front와 rear 인덱스가 같다는 것.
    if(pq->front == pq->rear) return TRUE;
    return FALSE;
}

int Full(Queue *pq)
{
    if((pq->rear + 1) % pq->max == pq->front) return TRUE;
    return FALSE;
}

int Front(Queue *pq)
{
    if(Empty(pq) == TRUE) return -1;
    return pq->data[(pq->front + 1) % pq->max];
}

int Back(Queue *pq)
{
    if(Empty(pq) == TRUE) return -1;
    return pq->data[pq->rear];
}

void Push(Queue *pq, int data)
{
    int i;
    int count;
    int *tmp;

    if(Full(pq) == TRUE) // 큐가 가득 찼을 때
    {
        // 1. 메모리 늘리기 전에 선처리
        // 임시 tmp배열을 max크기 만큼 메모리 할당을 해준다.
        tmp = (int *) malloc(pq->max * sizeof(int));
        // 큐의 크기를 count에 불러준다.
        count = pq->size;
        i = 0;
        while (i < count)
        {
            // 임시 tmp배열에 값을 담아준다.
            tmp[i] = Pop(pq);
            i++;
        }
        // 2. 메모리를 늘려서 기존 값 담아주는 후처리
        // max값을 2배로 키워준다.
        pq->max *= 2;
        // data배열을 2배로 늘린 max값 만큼 메모리를 할당한다.
        pq->data = (int *) realloc(pq->data, pq->max * sizeof(int));
        // data배열에 값이 없으면 리턴 처리
        if (!pq->data)
                return ;
        // 큐의 크기를 불러준다.
        count = pq->size;
        i = 0;
        while (i < count)
        {
            // 임시 배열 tmp에 담아둔 값을 사이즈를 늘린 pq에 푸쉬한다.
            Push(pq, tmp[i]);
            i++;
        }
        // 임심 배열 tmp 메모리를 해제한다.
        free(tmp);
        // 기존 값을 푸쉬한 이후에 추가로 푸쉬하고자 한 데이터를 푸쉬한다.
        Push(pq, data);
    }
    else
    {
        // 값 입력 시 front는 변화가 없고, rear가 움직이면서 데이터를 삽입
        // rear의 인덱스를 처리하는 문장
        /* 
            왜 rear + 1 % max 할까? 
        */
        // 예를 들어 큐 사이즈가 10인 상황일 때 index는 0 ~ 9를 부여 받는데,
        // 0 -> 9 까지 갈 때는 rear++ 로 가능하지만, 9 다음 업데이트가 0으로 되어야 된다는 점
        // if (pq->rear == MAX_SIZE - 1) pq->rear = 0; 으로 할 수 있지만
        // 매번 rear나 front변수를 업데이트 할 때마다 if문으로 검사하는 것보다 %나머지 연산자를 사용 한 것인데
        // pq->rear + 1 % MAX_SIZE와 같이 pq->rear + 1 해준 뒤에 MAX_SIZE로 나눠서 나머지를 확인하면
        // pq->rear + 1 < MAX_SIZE라면 pq->rear + 1 그대로 유지가 될 것이고, pq->rear + 1 == MAX_SIZE라면
        // MAX_SIZE % MAX_SIZE이므로 0이 나오게 된다.
        // 원형 큐에서는 위와 같은 방식으로 rear변수와 front변수를 업데이트한다.
        pq->rear = (pq->rear + 1) % pq->max;
        // 원형 큐 구조체에 선언 된 data배열에 데이터 삽입
        pq->data[pq->rear] = data;
        // 값을 삽입하면 큐의 사이즈를 늘린다.
        pq->size++;
    }
}

int Pop(Queue *pq)
{
    if(Empty(pq) == TRUE)
        return -1;
    // front가 움직이면서 데이터를 삭제한다. 큐는 뒤(rear)에서 데이터 삽입이 이뤄지고, 앞(front)에서 삭제가 이뤄짐.
    // front값을 움직이기때문에 front + 1한 후 % max 처리해서 인덱스를 가져온다.
    pq->front = (pq->front + 1) % pq->max;
    // 삭제한 뒤 큐의 크기를 줄인다.
    pq->size--;
    // 삭제 후 front값을 리턴해준다.
    return pq->data[pq->front];
    // pop함수에서는 return만 수행하고, 기존에 저장 된 값을 바꾸지 않는다.
    // front변수가 가르키고 있는 배열에는 data가 남아있겠지만, 공백 상태로 볼 것이라 상관없다.
}

int main(void)
{
    int     n;
    char    oper[6];
    int     i;
    int     data;
    Queue pq;

    scanf("%d", &n);
    InitQueue(&pq, 1000);

    i = 0;
    while(i < n)
    {
        scanf("%s", oper);

        if(strcmp(oper, "push") == 0)
        {
            scanf("%d", &data);
            Push(&pq, data);
        }
        else if(strcmp(oper, "pop") == 0)
        {
            printf("%d\n", Pop(&pq));
        }
        else if(strcmp(oper, "size") == 0)
        {
            printf("%d\n", pq.size);
        }
        else if(strcmp(oper, "empty") == 0)
        {
            printf("%d\n", Empty(&pq));
        }
        else if(strcmp(oper, "front") == 0)
        {
            printf("%d\n", Front(&pq));
        }
        else if(strcmp(oper, "back") == 0)
        {
            printf("%d\n", Back(&pq));
        }
        i++;
    }

    free(pq.data);
    return (0);
}

