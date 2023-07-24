#include<stdio.h>
#include<stdlib.h>
#include"Queue1.h"


int Initialize(IntQueue *q, int max1)
{
	q->que = calloc(max1, sizeof(int));// �迭�̸�
	q->max = max1;     //�ִ� ��� ����
	q->front = 0;// ��ó�� ������(��ť����)
	q->rear = 0;// �Ǹ����� ��� -1(��ť����)
	q->num = 0;       //ptr�� ���� ���� (��� ����)

}

int Enque(IntQueue *q, int x)// ������ �ֱ�
{
	if (q->num >= q->max)
	{
		return -1;
	}
	q->num++;
	q->que[q->rear++] = x;//rear�� ��ť�Ұ��� �̸�����Ű������
	if (q->rear == q->max)
	{
		q->rear = 0;
	}
	printf("q->front(��ť): %d\n", q->front);
	printf("q->rear(��ť): %d\n", q->rear);
	printf("num: %d\n", q->num);
	return;
}

int Deque(IntQueue *q, int *x)// ������ ���� 0����
{
	if (q->num <= 0)
	{
		return -1;
	}
	q->num--;
	*x = q->que[q->front++];    // num�������� �̸� �۾��� ������ front�� ��ť�� ��Ҹ� ����Ű������?
	
	if (q->front == q->max)
	{
		q->front = 0;
	}
	printf("q->front(��ť): %d\n", q->front);
	printf("q->rear(��ť): %d\n", q->rear);
	printf("num: %d\n", q->num);
}
int Peek(const IntQueue *q, int *x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[q->front];// �����͸� ������ �ʴ´�(��ť���� ���������� ����)

	return 0;
}

void Clear(IntQueue *q)
{
	q->num = 0;
	q->front = 0;
	q->rear = 0;
}

int Capacity(const IntQueue *q)
{
	return q->max;// (��Ҽ�)�ִ���
}

int Size(const IntQueue *q)
{
	return q->num;// (��Ҽ�)������
}

int IsEmpty(const IntQueue *q)
{
	return q->num <= 0;
}

int IsFull(const IntQueue *q)
{
	return q->num >= q->max;
}

int Search(const IntQueue *q, int x)
{
	for (int i = 0; i < q->num; i++)
	{
		int index;
		printf("q->front(��ť): %d\n", q->front);
		printf("q->rear(��ť): %d\n", q->rear);
		printf("num: %d\n", q->num);
		if (q->que[index = (q->front + i) % q->max] == x)
		{
			return index;
		}
	}
	return -1;
}

int Search2(const IntQueue *q, int x)
{
	for (int i = 0; i < q->num; i++)
	{
		printf("q->front(��ť): %d\n", q->front);
		printf("q->rear(��ť): %d\n", q->rear);
		printf("num: %d\n", q->num);
		if (q->que[(q->front + i) % q->max] == x)
		{
			return i;
		}
	}
	return -1;
}

void Print(const IntQueue *q)
{
	printf("----��");
	for (int i = 0; i < q->num; i++)
	{
		printf("%3d", q->que[(q->front + i) % q->max]);
	}
	putchar('\n');
}

void Terminate(IntQueue *q)
{
	q->num = 0;
	q->max = 0;
	q->front = 0;
	q->rear = 0;

	if (q->que != NULL)
	{
		free(q->que);
	}
}