#include"head.h"

/*
*函数引用以及局部函数定义
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
			printf("还没有输入选手信息！\n");
			Sleep(3000);
			return;
		}
		else
		{
			printf("这是输入信息：\n");
			printf("%-2s\t%-8s\t\t\t%-4s\t\t\t%-2s\t%-6s\n",
				"编号", "姓名", "评委打分", "总分","平均分");
			traverse(&list, showPartList);
		}
		traverse(&list, inputScore);
		system("cls");
		printf("%-2s\t%-8s\t\t\t%-4s\t\t\t%-2s\t%-6s\n",
			"编号", "姓名", "评委打分", "总分", "平均分");
		traverse(&list, showAllAverage);
		getchar();














		return;
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}
	getchar();
}

/*打分界面显示的部分信息界面*/
void showPartList(Singer singer)
{
	printf("%-2d\t%-8s\n", singer.num, singer.name);
}

/*显示已输入的总分和平均分*/
void showAllAverage(Singer singer)
{
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		printf("%-2s", singer.score[i]);
	}
}

/*输入评委对某一个选手打分*/
void inputScore(Singer singer)
{
	int i;

	for ( i = 0; i < 10; i++)
	{
		printf("第%d评委的打分：\n", (i + 1));
		scanf("%s", &temp.score[i]);
		while (getchar() != '\n')
			continue;
	}
}