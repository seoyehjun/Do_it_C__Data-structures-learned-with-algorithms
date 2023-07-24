#include<stdio.h>
#include<stdlib.h>
#include"IntStack.h"

int Initialize(IntStack *s, int max)
{
	s->ptr = 0;
	if ((s->stk = calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;
	}

	s->max = max;
	return 0;
}

int Push(IntStack *s, int x)
{
	if (s->ptr >= s->max)// ����� ������ �ִ��̰ų� ���̻�(��������)
	{
		return -1;
	}
	s->stk[s->ptr++] = x;

	return 0;
}

int Pop(IntStack *s, int *x)// ��ڰ��� �ϳ� ���̴°� �ٽ��̹Ƿ� ptr���� -1�ȴٴ°Ϳ� �ָ�����
{
	if (s->ptr <= 0)
	{
		return -1;// ����� ������ 0���̰ų� ������(��������)
	}
	s->ptr--;
	*x = s->stk[s->ptr];
}

int Peek(const IntStack *s, int *x)
{
	if (s->ptr <= 0)// ������ ������ �ϳ��� ���ٸ�
	{
		return -1;
	}
	*x = s->stk[s->ptr - 1];

	return 0;
}

void Clear(IntStack *s)
{
	s->ptr = 0;// ��Ҽ� ���ش�
}

int Capacity(const IntStack *s)
{
	return s->max;
}

int Size(const IntStack *s)
{
	return s->ptr;
}

int IsEmpty(const IntStack *s)
{
	return s->ptr <= 0;
}

int IsFull(const IntStack *s)
{
	return s->ptr >= 0;// �������� 1��ȯ
}

int Search(const IntStack *s, int x)
{
	for (int i = 0; i < s->max; i++)
	{
		if (s->stk[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void Print(const IntStack *s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		printf("%d", s->stk[i]);
	}
	putchar('\n');
}

void Terminate(IntStack *s)
{
	if (s->stk != NULL)
	{
		free(s->stk);
	}
	s->max = s->ptr = 0;
}