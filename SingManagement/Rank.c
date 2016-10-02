#include"head.h"
//跨文件问题解决了。哦耶！
extern List list;

extern void showlist(Singer singer);

void Rank(void)
{
	system("cls");
	if (listIsEmpty(&list))
	{
		printf("没有输入信息！\n");
	}
	else
	{
		printf("这是输入信息：\n");
		traverse(&list, showlist);
	}
	printf("你一共输入了%d个选手信息。\n", listItemCount(&list));
	Sleep(3000);
	return;
}
