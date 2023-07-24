#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"


int Initialize(IntQueue *q, int max1)
{
	q->que = calloc(max1, sizeof(int));// �迭�̸�
	q->max = max1;     //�ִ� ��� ����
	q->num = 0;       //ptr�� ���� ���� (��� ����)

}

int Enque(IntQueue *q, int x)// ������ �ֱ�
{
	if (q->num >= q->max)
	{
		return -1;
	}
	q->que[q->num++] = x;// num�� �������ڰ� �� �ε����� ����Ų��
	return;
}

int Deque(IntQueue *q, int *x)// ������ ���� 0����
{
	if (q->num <= 0)
	{
		return -1;
	}

	q->num--;// num�� �ϳ����̴°� �߿�����?
	*x = q->que[0];//��ť�� ������ [0]�ǰ��� ��������

	for (int i = 0; i < q->num; i++)//num�״�� ����ȴ� ������ �ϳ��������� �ϳ�����Ƚ����ŭ �����Ű���
	{
		q->que[i] = q->que[i + 1];
	}

}
int Peek(const IntQueue *q, int *x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[0];// �����͸� ������ �ʴ´�(��ť���� ���������� ����)

	return 0;
}

void Clear(IntQueue *q)
{
	q->num = 0;
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
		if (q->que[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void Print(const IntQueue *q)
{
	printf("---��");
	for (int i = 0; i < q->num; i++)
	{
		printf("%d", q->que[i]);
	}

}

void Terminate(IntQueue *q)
{
	q->num = 0;
	q->max = 0;
	if (q->que != NULL)
	{
		free(q->que);
	}
}