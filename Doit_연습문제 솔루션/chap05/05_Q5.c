/* Q5 �Լ� recur3�� ����������� ���� */
/* 
	�� ���α׷��� �����Ͽ��� 
	IntStack.h�� IntStack.c�� �ʿ��մϴ�. 
*/

#include <stdio.h>
#include "IntStack.h"

/*--- ��͸� ������ recur3 �Լ� ---*/
void recur3(int n)
{
	int sw = 0;
	IntStack nstk, sstk;			/* ���� */

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1) 
	{
		if (n > 0)// 0���� ū���
		{
			Push(&nstk, n);
			Push(&sstk, sw);

			if (sw == 0)// ù��° ȣ��(n-1������ �ٳ����� n-2���ν���)(=�������� �ѹ��߰��� ������ ����)
				n = n - 1;
			else if (sw == 1) // �ι�° ȣ��
			{
				n = n - 2;
				sw = 0;//���� Ǯ ��������
			}
			continue;
		}
		do 
		{
			Pop(&nstk, &n);
			Pop(&sstk, &sw);
			sw++;

			if (sw == 2)// ������(n-2)�Լ��� ���Ѵٴ� ����
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

	printf("������ �Է��ϼ���. : ");
	scanf("%d", &x);

	recur3(x);

	return 0;
}
