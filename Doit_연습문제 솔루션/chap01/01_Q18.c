#include<stdio.h>

int main(void)
{
	int *x;
	x = calloc(1, sizeof(int));//ũ�Ⱑ 1 * 4�� ������� x�� �Ҵ�.
	
	if (x == NULL)
	{
		puts("�޸� �Ҵ翡 �����߽��ϴ�");
	}
	else
	{
		*x = 69;
		printf("x = %d", *x);

		free(x);
	}

	return 0;

}