#include"head.h"

bool exitSys()
{
	FILE * fp;
	int i = 0;
	char ch;

	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{
		printf("��û�б���ѡ�����ݣ�ȷ���˳���(Y/N)\n");
		while ((i = getchar()) != '\n')
			;
		scanf("%c", &ch);

		switch (ch)
		{
		case 'Y':return true; break;
		case 'N':return false; break;
		default:printf("Yȷ����N�˳���\n");
			break;
		}
	}
	else
	{
		return true;
	}
}