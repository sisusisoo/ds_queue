#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {  // ���� ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
// ���� �Լ�

// ���� ť �ʱ�ȭ
void init_queue(QueueType* q)
{
	q->front = q->rear = 0; // 0�� �ƴ϶� �ٸ� ���� �ص� ��� ����
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ���� ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			if (is_empty(q)) {
				printf("============ť�� ��������Դϴ�===========");

				
			}
			else {
				i = (i + 1) % (MAX_QUEUE_SIZE);
				printf("%d | ", q->data[i]); 
			}
		} while (i != q->rear);//���� �� 
	}
	printf("\n");
}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))//�̰��� �̻���@@@@@@@@@@@@@@@@
	{
		printf("===========ť�� ��ȭ�����Դϴ�=============");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		printf("============ť�� ��������Դϴ�===========");
	}
	else{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
	
}


// ����

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


