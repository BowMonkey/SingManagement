
#include"head.h"

/*
*函数引用以及局部函数定义
*/
extern List list;
extern Singer temp;
void inputScore(Node *pnode);
void showList(Node *pnode);
double averageScore(Node *pnode);

void inputGrade(void)
{
	unsigned int i = 0;
	unsigned int j = 1;
	Node * pnode = list;
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
			//这个while检测有没有把所有节点赋值完（是否所有选手均被打分）
			while (j <= listItemCount(&list))
			{
				system("cls");
				showList(list);
				printf("请输入要打分的选手编号：");
				scanf("%d", &i);
				//检测所输编号是否超出范围
				while (i <= 0 || i>listItemCount(&list))
				{
					system("cls");
					showList(list);
					printf("编号超出范围！请重新输入：");
					scanf("%d", &i);
				}
				//找到对应编号的节点
				while (NULL != pnode)
				{
					if (pnode->singer.num == i)
						break;
					pnode = pnode->next;
				}

				inputScore(pnode);

				j++;
				
			}
		}
		system("cls");
		showList(list);	
		printf("所有分数输入完毕！");
		Sleep(3000);
		
		return;
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}
	getchar();
}


/*显示选手当前所有信息*/
void showList(Node *pnode)
{
	printf("这是已有选手信息：\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"编号", "姓名", "评委打分", "总分", "平均分");
	//traverse(&pnode, printf("%-2s\t%-8s", pnode->singer.num, pnode->singer.name));
	while (pnode != NULL)
	{
		printf("%-2d\t%-8s", pnode->singer.num, pnode->singer.name);

		for (size_t i = 0; i < 10; i++)
		{
			printf("%-4d", pnode->singer.score[i]);
		}
		printf("%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);
		pnode = pnode->next;
	}
}


/*输入评委对某一个选手打分*/
void inputScore(Node *pnode)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("第%d评委的打分：", (i + 1));
		scanf("%d", &pnode->singer.score[i]);
	}
	for ( i = 0; i < 10; i++)
	{
		pnode->singer.totalScore += pnode->singer.score[i];
	}
	pnode->singer.averageScore = averageScore(pnode);
}


/*计算并返回平均分函数*/
double averageScore(Node *pnode)
{
	int i = 0;
	int temp = 0;
	int sum = 0;
	int array[10];//新建array数组用来排序，保护原始数据
	bool swapped = true;
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = pnode->singer.score[i];
	}
	//冒泡排序score
	do
	{
		swapped = false;
		for (size_t i = 0; i < 9; i++)
		{
			if (array[i]>array[i+1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
	for (size_t i = 1; i <=8; i++)
	{
		sum += array[i];
	}
	return (sum / 8);
}