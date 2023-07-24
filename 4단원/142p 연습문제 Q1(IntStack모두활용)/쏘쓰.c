#include <stdio.h>
#include"IntStack.h"// �ϴ� �Լ��� �������� ���������ش�
enum stack_fun { PUSH = 1, POP, PEEK, PRINT, SEARCH, ISEMPTY, ISFULL, TERMINATE };
int main(void)
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("�ؽ��� ������ �����Ͽ����ϴ�.��");
		return 1;
	}


	while (1)
	{
		int menu, x, search_value, search_result;

		printf("\n��  ���� ������ �� : %d / %d  ��\n", Size(&s), Capacity(&s)); // Size()=>������ ����(ptr��), Capacity()=>������ �뷮(max��)
		printf("========= (1)Ǫ�� (2)�� (3)��ũ (4)���\n========= (5)������ �˻� (6)������� �˻� (7)�������� �˻�\n========= (8)������� ���� (0)����");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{

		case PUSH : /*---push---*/
			printf("������ :");
			scanf("%d", &x);
			if (Push(&s, x) == -1)//�̳� �ƴϳİ��ƴ� �ൿ(Ǫ��)�⶧����-1 ��ȯ
			{
				puts("\a�ؿ��� : Ǫ�ÿ� �����Ͽ����ϴ�.��\n");
			}
			break;

		case POP :/*---pop(���� �����������ε����� ������(x�� ����)---*/
			if (Pop(&s, &x)==-1)// x�� pop�� �����͸� ���� ���
			{
				puts("\a�ؿ��� : �˿� �����Ͽ����ϴ�.��\n");
			}
			else
			{
				printf("==���� ������(���� �ֱٿ� ���� ������)�� %d�Դϴ�\n", x);
			}
			break;

		case PEEK :
			if (Peek(&s, &x) == -1)
			{
				puts("\a�ؿ��� : ��ũ�� �����Ͽ����ϴ�.��\n");
			}
			else
			{
				printf("==����ũ �����ʹ� %d�Դϴ�.\n", x);// �˰� ����ϱ���?
			}
			break;

		case PRINT :
			Print(&s);
			break;
			
		case SEARCH:
			printf("==���˻��ϰ� ���� ���� �Է��ϼ���:");
			scanf("%d", &search_value);
			
			search_result = Search(&s, search_value);
			if (search_result == -1)
			{
				printf("==���˻�����");
			}
			else
			{
				printf("==��s.ptk[%d]", s.stk[search_result]);
			}
			break;
		case ISEMPTY:
			if (IsEmpty(&s))
			{
				printf("==������ֽ��ϴ�");
			}
			else
			{
				printf("==��������� �ʽ��ϴ�.");
			}
			break;
		case ISFULL:
			if (IsFull(&s))
			{
				printf("==�������ֽ��ϴ�.");
			}
			else
			{
				printf("==��������� �ʽ��ϴ�.");
			}
		case TERMINATE:
			Terminate(&s);// ������� free�ѵ� max=0 ptr=0���� �ʱ�ȭ
			break;
		}
	}
	Terminate(&s);

	return 0;
}
