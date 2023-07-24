#include<stdio.h>

int main(void)
{
	int *x;
	x = calloc(1, sizeof(int));//크기가 1 * 4인 저장공간 x에 할당.
	
	if (x == NULL)
	{
		puts("메모리 할당에 실패했습니다");
	}
	else
	{
		*x = 69;
		printf("x = %d", *x);

		free(x);
	}

	return 0;

}