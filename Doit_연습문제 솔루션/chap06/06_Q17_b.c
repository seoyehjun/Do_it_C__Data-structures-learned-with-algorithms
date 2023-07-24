/* Q17 퀵 정렬 (임의의 세 요소를 골라 가운데 요소를 피벗으로 사용 : 비재귀 버전) */
/* 이 프로그램의 컴파일에는 IntStack.h와 IntStack.c가 필요합니다. */
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int med3(int a, int b, int c)// 가운뎃 '값'반환
{
	if (a >= b)
	{
		if (b >= c)//※첫번째 조건※
		{
			return b;//  a b c 값이 같을수도 잇는경우 a >= b >= c 
		}
		else if (a <= c)//※두번째 조건※
		{
			return a; // c >= a >= b
		}
		else//※세번째 조건( a > c , c > b )※
		{
			return c; // a > c > b
		}
	}
	else if (a > c)// a < b, a > c
	{
		return a;// b > a > c
	}
	else if (b > c)//a < b, c >= a, b > c
	{
		return c;// b > c >= a 
	}
	else //a < b , c >= a, b <= c
	{
		return b;
	}
}

void insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

void quick(int a[], int left, int right)
{
	IntStack lstack;
	IntStack rstack;

	Initialize(&lstack, right - left + 1);// 요소 갯수만큼 할당
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);

	while (!IsEmpty(&lstack)) {
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = med3(a[pl], a[(pl + pr) / 2], a[pr]);// 가운데값 반환 ( x는 값이다-> 피벗값<3값중 중앙값> )

		if (right - left < 9)// 요소갯수9개 이하일시 단순삽입
			insertion(&a[left], right - left + 1);
		else 
		{
			do 
			{
				while (a[pl] < x) pl++;
				while (a[pr] > x) pr--;
				if (pl <= pr) 
				{
					swap(int, a[pl], a[pr]);
					pl++;
					pr--;
				}
			} while (pl <= pr);

			if (pr - left < right - pl) 
			{
				swap(int, pl, left);
				swap(int, pr, right);
			}
			if (left < pr) 
			{
				Push(&lstack, left);
				Push(&rstack, pr);	
			}
			if (pl < right) 
			{
				Push(&lstack, pl);	
				Push(&rstack, right);
			}
		}
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("퀵 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	quick(x, 0, nx - 1);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}
