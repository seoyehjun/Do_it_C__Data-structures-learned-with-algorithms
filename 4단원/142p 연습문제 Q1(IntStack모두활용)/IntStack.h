#ifndef ___IntStack// 만약 ___IntStack헤더파일이 선언되지 않앗다면(endif와 짝꿍으로 쓰인다)

#define ___IntStack// 선언
#include<stdio.h>

typedef struct
{
	int max;
	int ptr;
	int *stk;
} IntStack;


int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x);

int Pop(IntStack *s, int *x);

int Peek(const IntStack *s, int *x);

void Clear(IntStack *s);

int Capacity(const IntStack *s);

int Size(const IntStack *s);

int IsEmpty(const IntStack *s);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int x);

void Print(const IntStack *s);

void Terminate(IntStack *s);

#endif// 만약 선언되어있다면 중복선언피해서 일로온다