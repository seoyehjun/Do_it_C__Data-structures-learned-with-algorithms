#include<stdio.h>
#include<stdlib.h>
#include"Queue1.h"


int Initialize(IntQueue *q, int max1)
{
	q->que = calloc(max1, sizeof(int));// 배열이름
	q->max = max1;     //최대 요소 갯수
	q->front = 0;// 맨처음 넣은것(디큐전용)
	q->rear = 0;// 맨마지막 요소 -1(인큐전용)
	q->num = 0;       //ptr과 같은 존재 (요소 갯수)

}

int Enque(IntQueue *q, int x)// 데이터 넣기
{
	if (q->num >= q->max)
	{
		return -1;
	}
	q->num++;
	q->que[q->rear++] = x;//rear는 인큐할곳을 미리가리키고있음
	if (q->rear == q->max)
	{
		q->rear = 0;
	}
	printf("q->front(디큐): %d\n", q->front);
	printf("q->rear(인큐): %d\n", q->rear);
	printf("num: %d\n", q->num);
	return;
}

int Deque(IntQueue *q, int *x)// 데이터 빼기 0부터
{
	if (q->num <= 0)
	{
		return -1;
	}
	q->num--;
	*x = q->que[q->front++];    // num을쓸때는 미리 작업을 했지만 front는 디큐할 요소를 가르키고있죠?
	
	if (q->front == q->max)
	{
		q->front = 0;
	}
	printf("q->front(디큐): %d\n", q->front);
	printf("q->rear(인큐): %d\n", q->rear);
	printf("num: %d\n", q->num);
}
int Peek(const IntQueue *q, int *x)
{
	if (q->num <= 0)
	{
		return -1;
	}
	*x = q->que[q->front];// 데이터를 줄이진 않는다(디큐에서 꺼낼데이터 엿봄)

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
	return q->max;// (요소수)최대의
}

int Size(const IntQueue *q)
{
	return q->num;// (요소수)현재의
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
		printf("q->front(디큐): %d\n", q->front);
		printf("q->rear(인큐): %d\n", q->rear);
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
		printf("q->front(디큐): %d\n", q->front);
		printf("q->rear(인큐): %d\n", q->rear);
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
	printf("----▷");
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