#include <stdio.h>
#include"IntStack.h"

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
		int menu, x;

		printf("\n��  ���� ������ �� : %d / %d  ��\n", Size(&s), Capacity(&s)); // Size()=>������ ����(ptr��), Capacity()=>������ �뷮(max��)
		printf("==��(1)Ǫ�� (2)�� (3)��ũ (4)��� (0)���� :");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{

		case 1 : /*---push---*/
			printf("������ :");
			scanf("%d", &x);
			if (Push(&s, x) == -1)//�̳� �ƴϳİ��ƴ� �ൿ(Ǫ��)�⶧����-1 ��ȯ
			{
				puts("\a�ؿ��� : Ǫ�ÿ� �����Ͽ����ϴ�.��\n");
			}
			break;

		case 2 :/*---pop(���� �����������ε����� ������(x�� ����)---*/
			if (Pop(&s, &x)==-1)// x�� pop�� �����͸� ���� ���
			{
				puts("\a�ؿ��� : �˿� �����Ͽ����ϴ�.��\n");
			}
			else
			{
				printf("�� ������(���� �ֱٿ� ���� ������)�� %d�Դϴ�\n", x);
			}
			break;

		case 3 :
			if (Peek(&s, &x) == -1)
			{
				puts("\a�ؿ��� : ��ũ�� �����Ͽ����ϴ�.��\n");
			}
			else
			{
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);// �˰� ����ϱ���?
			}
			break;

		case 4 :
			Print(&s);
			break;

		}
	}
	Terminate(&s);

	return 0;
}
