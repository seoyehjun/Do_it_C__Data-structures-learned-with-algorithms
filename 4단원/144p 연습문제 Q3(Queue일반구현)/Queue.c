#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"


int Initialize(IntQueue *q, int max1)
{
	q->que = calloc(max1, sizeof(int));// 배열이름
	q->max = max1;     //최대 요소 갯수
	q->num = 0;       //ptr과 같은 존재 (요소 갯수)

}

int Enque(IntQueue *q, int x)// 데이터 넣기
{
	if (q->num >= q->max)
	{
		return -1;
	}
	q->que[q->num++] = x;// num은 다음숫자가 들어갈 인덱스를 가르킨다
	return;
}

int Deque(IntQueue *q, int *x)// 데이터 빼기 0부터
{
	if (q->num <= 0)
	{
		return -1;
	}

	q->num--;// num을 하나줄이는게 중요하죠?
	*x = q->que[0];//디큐는 무조건 [0]의것을 가져간다

	for (int i = 0; i < q->num; i++)//num그대로 쓰면된다 갯수가 하나빠졋으니 하나빠진횟수만큼 각각옮겨줌
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
	*x = q->que[0];// 데이터를 줄이진 않는다(디큐에서 꺼낼데이터 엿봄)

	return 0;
}

void Clear(IntQueue *q)
{
	q->num = 0;
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
		if (q->que[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void Print(const IntQueue *q)
{
	printf("---▷");
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