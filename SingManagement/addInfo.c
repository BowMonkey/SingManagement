
#include"head.h"

/*
*参数以及函数引用
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
				printf("无任何数据！请选择功能一添加。\n");
				exit;
			}
			else
			{
				//写入txt文件
			}
		}
		else
		{
			//新建链表——》从txt文件读数据到链表——》新增链表节点——》提示输入数据——》继续？
			//——》不继续，保存，退到主菜单

		}
















	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}

	getchar();
}