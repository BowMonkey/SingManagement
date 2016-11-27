
#include"head.h"

/*
*函数引用以及局部函数定义
*/
extern List list;
void inputScore(Node *pnode);
void showList(Node *node);
double averageScore(Node *pnode);
void Bubble_Sort(int *num,int n);

void inputGrade(void)
{
	bool numExist = true;
	unsigned int i = 0;
	unsigned int j = 1;
	int num = 0;
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
			/*这里while用的有问题，以后改！！！！
			*/
			//这个while检测有没有把所有节点赋值完（是否所有选手均被打分）
			while (j <= listItemCount(&list))
			{
				system("cls");
				showList(list);
				printf("请输入要打分的选手编号：");
				scanf("%u", &num);
			rechoose:
				pnode = list;
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

				if (numExist)
				{
					//找到对应编号的节点
					while (NULL != pnode)
					{
						if (pnode->singer.num == num)
							break;
						pnode = pnode->next;
					}

					inputScore(pnode);
					//经过上面循环之后pnode已不指向链表开始位置，所以重新赋值
					pnode = list;
					j++;
				}
				else
				{
					system("cls");
					showList(list);
					printf("编号不存在！请重新输入：");
					scanf("%d", &num);
					goto rechoose;
				}
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
void showList(Node *node)
{
	Node * pnode = node;
	printf("这是已有选手信息：\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"编号", "姓名", "评委打分", "总分", "平均分");
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
	for (i = 0; i < 10; i++)
	{
		pnode->singer.totalScore += pnode->singer.score[i];
	}
	pnode->singer.averageScore = averageScore(pnode);
}


/*计算并返回平均分函数*/
double averageScore(Node *pnode)
{
	int i;
	int sum = 0;
	int array[10];//新建array数组用来排序，保护原始数据
	//给用于排序的数组赋值
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = pnode->singer.score[i];
	}
	//排序
	Bubble_Sort(array,(sizeof(array)/sizeof(int)));
	//计算平均分
	for (size_t i = 1; i <= 8; i++)
	{
		sum += array[i];
	}
	return (sum / 8);
}


//冒泡排序
//使用前先将链表中要排序的数据循环复制给一个新的数组num
//再将新建的数组名传递给本函数
void Bubble_Sort(int * num,int n)
{
	int i = 0;
	int temp = 0;
	bool swapped = true;
	do
	{
		swapped = false;
		for (size_t i = 0; i < n-1; i++)
		{
			if (num[i] > num[i + 1])
			{
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
	return;
}