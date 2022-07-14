#include <stdio.h>
#include <stdlib.h>

// 대기열 항목을 저장하기 위한 연결 목록 노드
struct QNode {
	int key;
	struct QNode* next;
};

//큐, front는 앞 노드를 저장하고, rear는 LL의 마지막 노드를 저장.
struct Queue {
	struct QNode *front, *rear;
};

// 새 연결 목록 노드를 만드는 유틸리티 함수.
struct QNode* newNode(int k)
{
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// 빈 큐를 생성하는 유틸리티 함수
struct Queue* createQueue()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

// 키 k를 q에 추가하는 함수
void enQueue(struct Queue* q, int k)
{
	// 새 링크드 리스트 생성
	struct QNode* temp = newNode(k);

	// 큐가 비어 있으면 새노드의 front와 rear가 동일합니다.
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// 큐의 끝에 새 노드를 추가하고 rear를 변경
	q->rear->next = temp;
	q->rear = temp;
}

// 주어진 큐 q에서 킬를 제거하는 함수
void deQueue(struct Queue* q)
{
	// 큐가 비어있으면 NULL을 반환
	if (q->front == NULL)
		return;

	// 이전 front를 저장하고 front를 한 노드 앞으로 이동
	struct QNode* temp = q->front;

	q->front = q->front->next;

	// front가 NULL이 되면 rear도 NULL로 변경
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}

int main()
{
	struct Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	deQueue(q);
	deQueue(q);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	deQueue(q);
	printf("Queue Front : %d \n", q->front->key);
	printf("Queue Rear : %d", q->rear->key);
	return 0;
}
