
#include"head.h"

/*
*参数以及函数引用
*/
extern List list;
extern void showList(Node *node);
extern void Bubble_Sort(int * num, int n);


void addInfo()
{
	int i;
	int sum = 0;
	char ch;
	int array[10];
	Node *pnode = list;
	Singer newSinger;


	if (check())
	{
		if (listIsEmpty(&list))
		{
			printf("还没有输入信息,请选择功能一进行输入！\n");
			Sleep(3000);
			return;
		}
		else
		{
		reAdd:
			system("cls");
			showList(pnode);
			printf("请输入要添加的选手编号：");
			scanf("%u", &newSinger.num);
			printf("请输入要添加的选手姓名：");
			scanf("%s", &newSinger.name);
			printf("请输入要添加的选手性别：");
			scanf("%s", &newSinger.sex);
			printf("请输入要添加的选手电话号码：");
			scanf("%s", &newSinger.phoneNum);
			printf("请输入要添加的选手的评委评分：\n");
			for (size_t i = 0; i < 10; i++)
			{
				printf("第%d评委的打分：", (i + 1));
				scanf("%d", &newSinger.score[i]);
			}
			//计算总分
			newSinger.totalScore = 0;
			for (size_t i = 0; i < 10; i++)
			{
				newSinger.totalScore += newSinger.score[i];
			}
			//计算平均分
			for (size_t i = 0; i < (sizeof(array) / sizeof(int)); i++)
			{
				array[i] = newSinger.score[i];
			}
			Bubble_Sort(array, sizeof(array) / sizeof(int));
			for (size_t i = 1; i < (sizeof(array) / sizeof(int)) - 2; i++)
			{
				sum += array[i];
			}
			newSinger.averageScore = (sum / 8);
			//使用addItem(Singer singer, List * plist);接口添加singer到链表
			if (addItem(newSinger, &pnode))
			{
				printf("添加信息成功！\n");
				system("cls");
				showList(pnode);
				printf("继续添加信息？(y/n)\n");
			rechoose:
				while ((i = getchar()) != '\n')
					;
				scanf("%c", &ch);
				switch (ch)
				{
				case 'y':goto reAdd;
				case 'n':return;
				default:printf("y确定，n退出！\n");
					goto rechoose;
				}
			}
			else
			{
				printf("添加信息失败！\n");
				Sleep(3000);
				return;
			}

		}
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}

}