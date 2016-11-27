#include"head.h"

bool exitSys()
{
	FILE * fp;
	int i = 0;
	char ch;

	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{
		printf("还没有保存选手数据！确定退出？(y/n)\n");
	rechoose:
		while ((i = getchar()) != '\n')
			;
		scanf("%c", &ch);
		switch (ch)
		{
		case 'y':return true; break;
		case 'n':return false; break;
		default:printf("y确定，n退出！\n");
			goto rechoose;
		}
	}
	else
	{
		return true;
	}
}