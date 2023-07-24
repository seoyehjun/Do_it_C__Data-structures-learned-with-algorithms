#include <stdio.h>
#include"IntStack.h"// 일단 함수를 쓰기위해 선언을해준다
enum stack_fun { PUSH = 1, POP, PEEK, PRINT, SEARCH, ISEMPTY, ISFULL, TERMINATE };
int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("※스택 생성에 실패하였습니다.※");
		return 1;
	}


	while (1)
	{
		int menu, x, search_value, search_result;

		printf("\n§  현재 데이터 수 : %d / %d  §\n", Size(&s), Capacity(&s)); // Size()=>데이터 개수(ptr값), Capacity()=>스택의 용량(max값)
		printf("========= (1)푸시 (2)팝 (3)피크 (4)출력\n========= (5)데이터 검색 (6)비엇는지 검사 (7)꽉찻는지 검사\n========= (8)저장공간 해재 (0)종료");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{

		case PUSH : /*---push---*/
			printf("데이터 :");
			scanf("%d", &x);
			if (Push(&s, x) == -1)//이냐 아니냐가아닌 행동(푸쉬)기때문에-1 반환
			{
				puts("\a※오류 : 푸시에 실패하였습니다.※\n");
			}
			break;

		case POP :/*---pop(재일 마지막에쌓인데이터 꺼내기(x에 저장)---*/
			if (Pop(&s, &x)==-1)// x는 pop한 데이터를 담을 장소
			{
				puts("\a※오류 : 팝에 실패하였습니다.※\n");
			}
			else
			{
				printf("==▷팝 데이터(제일 최근에 쌓인 데이터)는 %d입니다\n", x);
			}
			break;

		case PEEK :
			if (Peek(&s, &x) == -1)
			{
				puts("\a※오류 : 피크에 실패하였습니다.※\n");
			}
			else
			{
				printf("==▷피크 데이터는 %d입니다.\n", x);// 팝과 비슷하구만?
			}
			break;

		case PRINT :
			Print(&s);
			break;
			
		case SEARCH:
			printf("==▷검색하고 싶은 값을 입력하세요:");
			scanf("%d", &search_value);
			
			search_result = Search(&s, search_value);
			if (search_result == -1)
			{
				printf("==▷검색실패");
			}
			else
			{
				printf("==▷s.ptk[%d]", s.stk[search_result]);
			}
			break;
		case ISEMPTY:
			if (IsEmpty(&s))
			{
				printf("==▷비어있습니다");
			}
			else
			{
				printf("==▷비어있지 않습니다.");
			}
			break;
		case ISFULL:
			if (IsFull(&s))
			{
				printf("==▷꽉차있습니다.");
			}
			else
			{
				printf("==▷비어있지 않습니다.");
			}
		case TERMINATE:
			Terminate(&s);// 저장공간 free한뒤 max=0 ptr=0으로 초기화
			break;
		}
	}
	Terminate(&s);

	return 0;
}
