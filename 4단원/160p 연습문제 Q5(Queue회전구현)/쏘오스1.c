#include<stdio.h>
#include<stdlib.h>
#include"Queue1.h"

enum Queue_func { INITIALIZE, ENQUE, DEQUE, PEEK, CLEAR, CAPACITY, SIZE, ISEMPTY, ISFULL, SEARCH, PRINT, TERNIMATE };

int main(void)
{
	IntQueue q;
	

	if ((Initialize(&q, 8)) == NULL)
	{
		printf("����Ȯ���� �����߽��ϴ�.");
		exit(1);
	}
	while (1)
	{
		int menu, x;
		printf("\n��  ���� ������ �� : %d / %d  ��\n", Size(&q), Capacity(&q)); // Size()=>������ ����(num��), Capacity()=>������ �뷮(max��)
		printf("========= (1)��ť (2)��ť (3)��ũ (4)��ҵ� ����\n========= (5)��ü��Ҽ� (6)������Ҽ� (7)������� �˻�\n========= (8)�������� �˻� (9)������ �˻� (10)��� (11)������� ����");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case ENQUE :

			printf("�ְ���� �����͸� �Է��ϼ���:");
			scanf("%d", &x);

			if (Enque(&q, x) == -1)
			{
				printf("�����͸� �ִµ� �����߽��ϴ�(������ ����)\n");
			}

			break;

		case DEQUE :
			
			if (Deque(&q, &x) == -1)
			{
				printf("�����͸� ���µ� �����߽��ϴ�(�����Ͱ� ����)\n");
				break;
			}
			printf("���� �����ʹ� %d�Դϴ�.\n",x);

			break;
		
		case PEEK :
			
			if (Peek(&q, &x) == -1)
			{
				printf("�����͸� ���µ� �����߽��ϴ�(�����Ͱ� ����)\n");
				break;
			}
			printf("���� �ֱٿ� ���� �����ʹ�%d�Դϴ�.\n", x);
			
			break;
			
		case CLEAR:

			Clear(&q);

			break;

		case CAPACITY :

			printf("�ִ��Ҽ� : %d\n", Capacity(&q));
			
			break;

		case SIZE :

			printf("���� ��Ҽ� : %d\n", Size(&q));

			break;
		
		case ISEMPTY:
			if (IsEmpty(&q) == 1)
			{
				printf("ť�� ����ֽ��ϴ�\n");
			}
			else if (IsEmpty(&q) == 0)
			{
				printf("ť�� ��������ʽ��ϴ�\n");
			}
			break;
			
		case ISFULL:
			if (IsFull(&q) == 1)
			{
				printf("ť�� �����ֽ��ϴ�.\n");
			}
			else if (IsFull(&q) == 0)
			{
				printf("ť�� ���������ʽ��ϴ�.\n");
			}
			break;

		case SEARCH :

			printf("ã����� ���� �Է��ϼ���\n");
			scanf("%d", &x);

			if (Search(&q,x) != -1)
			{
				printf("ã�°��� que[%d]�� �ֽ��ϴ�.\n", Search(&q, x));
			}
			else// -1��ȯ�� (����)
			{
				printf("ã�°��� �������� �ʽ��ϴ�.\n");
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
