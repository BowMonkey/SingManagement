#include"head.h"

/*
*���������Լ��ֲ���������
*/
extern List list;
extern Singer temp;
extern void showlist(Singer singer);
void showPartList(Singer singer);
void showAllAverage(Singer singer);
void inputScore(Singer singer);


void inputGrade(void)
{
	int i,j;

	if (check())
	{
		system("cls");
		if (listIsEmpty(&list))
		{
			printf("��û������ѡ����Ϣ��\n");
			Sleep(3000);
			return;
		}
		else
		{
			printf("����������Ϣ��\n");
			printf("%-2s\t%-8s\t\t\t%-4s\t\t\t%-2s\t%-6s\n",
				"���", "����", "��ί���", "�ܷ�","ƽ����");
			traverse(&list, showPartList);
		}
		traverse(&list, inputScore);
		system("cls");
		printf("%-2s\t%-8s\t\t\t%-4s\t\t\t%-2s\t%-6s\n",
			"���", "����", "��ί���", "�ܷ�", "ƽ����");
		traverse(&list, showAllAverage);
		getchar();














		return;
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}
	getchar();
}

/*��ֽ�����ʾ�Ĳ�����Ϣ����*/
void showPartList(Singer singer)
{
	printf("%-2d\t%-8s\n", singer.num, singer.name);
}

/*��ʾ��������ֺܷ�ƽ����*/
void showAllAverage(Singer singer)
{
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		printf("%-2s", singer.score[i]);
	}
}

/*������ί��ĳһ��ѡ�ִ��*/
void inputScore(Singer singer)
{
	int i;

	for ( i = 0; i < 10; i++)
	{
		printf("��%d��ί�Ĵ�֣�\n", (i + 1));
		scanf("%s", &temp.score[i]);
		while (getchar() != '\n')
			continue;
	}
}