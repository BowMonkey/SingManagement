#include"head.h"
//���ļ��������ˡ�ŶҮ��
extern List list;

extern void showlist(Singer singer);

void Rank(void)
{
	system("cls");
	if (listIsEmpty(&list))
	{
		printf("û��������Ϣ��\n");
	}
	else
	{
		printf("����������Ϣ��\n");
		traverse(&list, showlist);
	}
	printf("��һ��������%d��ѡ����Ϣ��\n", listItemCount(&list));
	Sleep(3000);
	return;
}
