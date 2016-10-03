#include"head.h"

bool exitSys()
{
	FILE * fp;
	int i = 0;
	char ch;

	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{
		printf("还没有保存选手数据！确定退出？(Y/N)\n");
		while ((i = getchar()) != '\n')
			;
		scanf("%c", &ch);

		switch (ch)
		{
		case 'Y':return true; break;
		case 'N':return false; break;
		default:printf("Y确定，N退出！\n");
			break;
		}
	}
	else
	{
		return true;
	}
}