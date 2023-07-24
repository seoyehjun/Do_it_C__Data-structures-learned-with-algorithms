/* Q10 이진 삽입 정렬 */
#include <stdio.h>
#include <stdlib.h>

/*--- 이진 삽입 정렬 ---*/
void bin_insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		int key = a[i];
		int pl = 0;		/* 검색 범위의 첫 인덱스 */
		int pr = i - 1;	/* 검색 범위의 끝 인덱스 */
		int pc;			/* 검색 범위의 가운데 인덱스 */
		int pd;			/* 삽입하는 위치의 인덱스 */

		do 
		{
			pc = (pl + pr) / 2;
			if (a[pc] == key)		/* 검색 성공 */
				break;
			else if (a[pc] < key)// 키값이 정렬된것들보다 크다면 pr값이 수정되지않는다.
				pl = pc + 1;
			else
				pr = pc - 1;// 키값이 계속 크다면 pr수정안됨 그래서 
		} while (pl <= pr);
		pd = (pl <= pr) ? /* 찾은경우pl <= pr */pc + 1 :/* 못찾은경우(pl > pr) */ pr + 1/*pr+1에는 키값보다 큰값이잇다*/;
		                                  
		for (j = i; j > pd; j--)// 조건검사를 따로안해줘도 된다앙~
			a[j] = a[j - 1];/*pr+2까지 대입당한다*/
		a[pd] = key;//pr+1에는 키값 대입한다
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("이진 삽입 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bin_insertion(x, nx);			

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);	

	return 0;
}
