#include"head.h"

bool exitSys()
{
	FILE * fp;
	int i = 0;
	char ch;

	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{
		printf("��û�б���ѡ�����ݣ�ȷ���˳���(y/n)\n");
	rechoose:
		while ((i = getchar()) != '\n')
			;
		scanf("%c", &ch);
		switch (ch)
		{
		case 'y':return true; break;
		case 'n':return false; break;
		default:printf("yȷ����n�˳���\n");
			goto rechoose;
		}
	}
	else
	{
		return true;
	}
}