/* Q5 함수 recur3을 비재귀적으로 구현 */
/* 
	이 프로그램의 컴파일에는 
	IntStack.h와 IntStack.c가 필요합니다. 
*/

#include <stdio.h>
#include "IntStack.h"

/*--- 재귀를 제거한 recur3 함수 ---*/
void recur3(int n)
{
	int sw = 0;
	IntStack nstk, sstk;			/* 스택 */

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) 
	{
		if (n > 0)// 0보다 큰경우
		{
			Push(&nstk, n);
			Push(&sstk, sw);

			if (sw == 0)// 첫번째 호출(n-1라인을 다끝낸뒤 n-2라인시작)(=왼쪽으로 한번쭉간뒤 오른쪽 봐줌)
				n = n - 1;
			else if (sw == 1) // 두번째 호출
			{
				n = n - 2;
				sw = 0;//현재 풀 빠져나감
			}
			continue;
		}
		do 
		{
			Pop(&nstk, &n);
			Pop(&sstk, &sw);
			sw++;

			if (sw == 2)// 오른쪽(n-2)함수도 돌앗다는 증거
			{
				printf("%d\n", n);
				if (IsEmpty(&nstk))
					return;
			}
		} while (sw == 2);
	}

	Terminate(&nstk);
	Terminate(&sstk);
}

int main(void)
{
	int x;

	printf("정수를 입력하세요. : ");
	scanf("%d", &x);

	recur3(x);

	return 0;
}
