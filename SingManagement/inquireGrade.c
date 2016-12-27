#include"head.h"

/*
局部函数定义
*/
extern List list;
extern void showList(Node *node);

void inquireGrade()
{
	int i;
	int num = 0;
	Node * pnode = list;
	bool numExist = true;
	system("cls");

	if (listIsEmpty(&list))
	{
		printf("没有输入信息！\n");
		Sleep(3000);
		return;
	}
	else
	{
		printf("请选择要查询的选手编号：");
		scanf("%d", &num);
	rechoose:
		//检测所输编号是否存在,存在numExit置为true,否则false
		for (size_t i = 0; i < listItemCount(&list); i++)
		{
			if (num == pnode->singer.num)
			{
				numExist = true;
				break;
			}
			else
			{
				numExist = false;
			}
			pnode = pnode->next;
		}
		//经过上面循环之后pnode已不指向链表开始位置，所以重新赋值
		pnode = list;
		while ((i = getchar()) != '\n')
			;
		if (numExist)
		{
			//找到对应编号的节点
			system("cls");
			while (NULL != pnode)
			{
				if (pnode->singer.num == num)
				{
					printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
						"编号", "姓名", "评委打分", "总分", "平均分");
					printf("%-2d\t%-8s", pnode->singer.num, pnode->singer.name);

					for (size_t i = 0; i < 10; i++)
					{
						printf("%-4d", pnode->singer.score[i]);
					}
					printf("%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);
					printf("按回车退出。");
					while ((i = getchar()) != '\n')
						;
					return;
				}
					
				pnode = pnode->next;
			}

			pnode = list;
		}
		else
		{
			system("cls");
			//showList(list);
			printf("编号不存在！请重新输入：");
			scanf("%d", &num);
			goto rechoose;
		}
	}
}

