
#include"head.h"

/*
*�����Լ���������
*/
extern List list;
extern Singer temp;
extern void showlist(Singer singer);

void addInfo()
{
	FILE * fp;

	if (check())
	{
		fp = fopen("Doc.txt", "r+");
		if (NULL == fp)
		{
			if (listIsEmpty(&list))
			{
				printf("���κ����ݣ���ѡ����һ��ӡ�\n");
				exit;
			}
			else
			{
				//д��txt�ļ�
			}
		}
		else
		{
			//�½�����������txt�ļ������ݵ�����������������ڵ㡪������ʾ�������ݡ�����������
			//�����������������棬�˵����˵�

		}
















	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}

	getchar();
}