#include"head.h"

/*
�ֲ���������
*/
extern List list;
extern Singer temp;
void searchFile(int num);
void searchTable(int num);

void inquireGrade()
{
	int i, j;

	system("cls");
	printf("������Ҫ��ѯ��ѡ�ֱ�ţ�");
	scanf("%d", &i);
	
rechoose:
	printf("һ���������ɵ������ļ���ѯ\n");
	printf("�����������в�ѯ\n");
	printf("��ѡ���ѯԴ��");
	
	scanf("%d", &j);

	switch (j)
	{
	case 1:searchFile(i); break;
	case 2:searchTable(i); break;
	default:printf("������1����2��\n");
		goto rechoose;
		break;
	}

}

/*��Doc.txt�ļ��в�ѯ��Ӧ�����Ϣ*/
void searchFile(int num)
{
	FILE * fp;
	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{
		printf("�ļ�Doc.txt�����ڣ���ѡ��������ʽ��ѯ��\n");
		Sleep(3000);
		exit;
	}
	else
	{
		//���ļ���ȡ���ݵ�������������ѯ
		;
	}
}


/*�������в�ѯ��Ӧ��Ϣ*/
void searchTable(int num)
{

}