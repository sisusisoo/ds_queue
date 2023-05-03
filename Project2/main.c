#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {  // 원형 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
// 오류 함수

// 원형 큐 초기화
void init_queue(QueueType* q)
{
	q->front = q->rear = 0; // 0이 아니라 다른 수로 해도 상관 없음
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형 큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			if (is_empty(q)) {
				printf("============큐가 공백상태입니다===========");

				
			}
			else {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%d | ", q->data[i]); 
			}
		} while (i != q->rear);//수정 완 
	}
	printf("\n");
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))//이거좀 이상함@@@@@@@@@@@@@@@@
	{
		printf("===========큐가 포화상태입니다=============");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		printf("============큐가 공백상태입니다===========");
	}
	else{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
	
}


// 메인

void selecting(QueueType* q, int inputSel) {
	int inputNum = 0;
	int outputNum;
	switch (inputSel) {
	case 1:
		printf("Input data:");
		scanf_s("%d", &inputNum);

		enqueue(q, inputNum);

		printf("\n");
		break;
	case 2:
		
		outputNum=dequeue(q);
		printf("%d\n", outputNum);
		break;
	case 3:
		queue_print(q);
		break;
	case 4: 
		exit(1);


	}

}

int main() {
	QueueType q;
	init_queue(&q);
	int exit = 1;
	while (exit) {
		int inputSel = 0;
		int inputNum = 0;
		printf("==== Menu ====\n");
		printf("1. Input data and Enqueue\n");
		printf("2. Dequeue and Print data\n");
		printf("3. Print Queue \n");
		printf("4. Exit\n");
		printf("Select number: ");
		scanf_s("%d", &inputSel);

		selecting(&q, inputSel);






	}
}


