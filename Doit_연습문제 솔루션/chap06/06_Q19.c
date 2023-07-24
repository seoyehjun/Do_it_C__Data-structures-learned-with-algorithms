/* Q19 qsort 함수로 문자열 배열 정렬 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- 문자열 배열(n1 × n2의 2차원 배열)을 오름차순으로 정렬 ---*/
void sort_2dstr(char *p, int n1, int n2)// n2는 2차원 요소 하나의 크기
{
	qsort(p, n1, n2, (int(*)(const void *, const void *))strcmp);//strcmp는 매개변수로 포인터를 받내?
}

/*--- x, y가 가리키는 문자열 비교 함수 ---*/
static int pstrcmp(const void *x, const void *y)// 포인터 배열전용
{
	return strcmp(*(const char **)x, *(const char **)y);//x는 문자열 주소를 담는 포인터일텐데
}

/*--- 문자열을 가리키는 p를 오름차순으로 정렬 ---*/
void sort_pvstr(char *p[], int n)// 2중포인터 매개변수
{
	qsort(p, n, sizeof(char *), pstrcmp);// 임의로 구현된 오름차순함수 사요야
}

int main(void)
{
	
	int  i;
	char a[][7] = { "LISP", "C", "Ada", "Pascal" };
	char *p[] = { "LISP", "C", "Ada", "Pascal" };

	sort_2dstr(&a[0][0], 4, 7);

	sort_pvstr(p, 4);

	puts("오름차순으로 정렬했습니다.");

	for (i = 0; i < 4; i++)
		printf("a[%d] = %s\n", i, a[i]);

	for (i = 0; i < 4; i++)
		printf("p[%d] = %s\n", i, p[i]);

	return 0;
}
