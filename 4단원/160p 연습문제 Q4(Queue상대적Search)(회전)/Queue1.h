#ifndef ___IntQueue
#define ___IntQueue

typedef struct
{
	int max;
	int num;
	int *que;
	int front;// ��ť��
	int rear;// ��ť��
} IntQueue;

int Initialize(IntQueue *q, int max);

int Enque(IntQueue *q, int x);

int Deque(IntQueue *q, int *x);

int Peek(const IntQueue *q, int *x);

void Clear(IntQueue *q);

int Capacity(const IntQueue *q);

int Size(const IntQueue *q);

int IsEmpty(const IntQueue *q);

int IsFull(const IntQueue *q);

int Search(const IntQueue *q, int x);

int Search2(const IntQueue *q, int x);

void Print(const IntQueue *q);

void Terminate(IntQueue *q);


#endif