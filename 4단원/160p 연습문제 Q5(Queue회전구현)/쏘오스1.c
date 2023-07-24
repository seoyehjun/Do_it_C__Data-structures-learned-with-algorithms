#include<stdio.h>
#include<stdlib.h>
#include"Queue1.h"

enum Queue_func { INITIALIZE, ENQUE, DEQUE, PEEK, CLEAR, CAPACITY, SIZE, ISEMPTY, ISFULL, SEARCH, PRINT, TERNIMATE };

int main(void)
{
	IntQueue q;
	

	if ((Initialize(&q, 8)) == NULL)
	{
		printf("공간확보에 실패했습니다.");
		exit(1);
	}
	while (1)
	{
		int menu, x;
		printf("\n§  현재 데이터 수 : %d / %d  §\n", Size(&q), Capacity(&q)); // Size()=>데이터 개수(num값), Capacity()=>스택의 용량(max값)
		printf("========= (1)엔큐 (2)디큐 (3)피크 (4)요소들 삭제\n========= (5)전체요소수 (6)현제요소수 (7)비엇는지 검사\n========= (8)꽉찻는지 검사 (9)데이터 검색 (10)출력 (11)저장공간 해지");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case ENQUE :

			printf("넣고싶은 데이터를 입력하세요:");
			scanf("%d", &x);

			if (Enque(&q, x) == -1)
			{
				printf("데이터를 넣는데 실패했습니다(공간이 꽉참)\n");
			}

			break;

		case DEQUE :
			
			if (Deque(&q, &x) == -1)
			{
				printf("데이터를 빼는데 실패했습니다(데이터가 없음)\n");
				break;
			}
			printf("빼낸 데이터는 %d입니다.\n",x);

			break;
		
		case PEEK :
			
			if (Peek(&q, &x) == -1)
			{
				printf("데이터를 보는데 실패했습니다(데이터가 없음)\n");
				break;
			}
			printf("제일 최근에 넣은 데이터는%d입니다.\n", x);
			
			break;
			
		case CLEAR:

			Clear(&q);

			break;

		case CAPACITY :

			printf("최대요소수 : %d\n", Capacity(&q));
			
			break;

		case SIZE :

			printf("현재 요소수 : %d\n", Size(&q));

			break;
		
		case ISEMPTY:
			if (IsEmpty(&q) == 1)
			{
				printf("큐가 비어있습니다\n");
			}
			else if (IsEmpty(&q) == 0)
			{
				printf("큐가 비어있지않습니다\n");
			}
			break;
			
		case ISFULL:
			if (IsFull(&q) == 1)
			{
				printf("큐가 꽉차있습니다.\n");
			}
			else if (IsFull(&q) == 0)
			{
				printf("큐가 꽉차있지않습니다.\n");
			}
			break;

		case SEARCH :

			printf("찾고싶은 값을 입력하세요\n");
			scanf("%d", &x);

			if (Search(&q,x) != -1)
			{
				printf("찾는값은 que[%d]에 있습니다.\n", Search(&q, x));
			}
			else// -1반환시 (실패)
			{
				printf("찾는값이 존재하지 않습니다.\n");
			}
			break;

		case PRINT:
			
			Print(&q);
			break;

		case TERNIMATE:

			Terminate(&q);
			break;

		}
	}

	return 0;
}
