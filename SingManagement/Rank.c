
#include"head.h"

/*
*函数引用以及局部函数定义
*/
extern List list;
extern void showList(Node *node);
extern void Bubble_Sort(int *num, int n);
void inTotalOrder(Node *node);
void inAverageOrder(Node *node);
void BubbleSort(double *num, int n);


void Rank(void)
{
	int i;
	Node * pnode = list;
	system("cls");
	if (listIsEmpty(&list))
	{
		printf("没有输入信息！\n");
		Sleep(3000);
		return;
	}
	else if (list->singer.totalScore == 0)
	{
		printf("暂无分数信息！\n");
		Sleep(3000);
		return;
	}
	else
	{
		//printf("这是已有信息：\n");
		//showList(list);

	rechoose:
		printf("一：按编号顺序显示\n");
		printf("二：按总分顺序显示\n");
		printf("三：按平均分顺序显示\n");
		printf("请选择排序方式：");
		scanf("%d", &i);
		switch (i)
		{
		case 1: system("cls");
			showList(list);
			while (getchar() != '\n')
				continue;
			break;
		case 2:system("cls");
			inTotalOrder(pnode);
			while (getchar() != '\n')
				continue;
			break;
		case 3:system("cls");
			inAverageOrder(pnode);
			while (getchar() != '\n')
				continue;
			break;
		default:printf("请输入1、2或者3！\n");
			goto rechoose;
			break;
		}
	}

	printf("按回车退出。");
	while ((i = getchar()) != '\n')
		;
	return;
}


//按照总分从小到大显示
void inTotalOrder(Node *node)
{
	int i, j, c;
	Node *pnode = node;
	//链表长度不确定，使用动态数组
	int * array;
	array = (int*)malloc(listItemCount(&list) * sizeof(int));
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		array[i] = pnode->singer.totalScore;
		pnode = pnode->next;
	}

	pnode = list;
	//排序
	Bubble_Sort(array, listItemCount(&list));

	pnode = list;
	printf("按总分排序：\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"编号", "姓名", "评委打分", "总分", "平均分");
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		for (size_t j = 0; j < listItemCount(&list); j++)
		{
			if (array[i] == pnode->singer.totalScore)
			{
				//输出当前节点的选手信息
				printf("%-2d\t%-8s", pnode->singer.num, pnode->singer.name);
				for (size_t c = 0; c < 10; c++)
				{
					printf("%-4d", pnode->singer.score[c]);
				}
				printf("%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);
			}
			pnode = pnode->next;
		}
		pnode = list;
	}
	//释放内存
	free(array);
	return;
}

/*这个函数和inTotalOrder()几乎一样，最好能做成公有方法，通过传递参数来实现对不同主键排序*/
//按照平均分从小到大显示
void inAverageOrder(Node *node)
{
	int i, j, c;
	Node *pnode = node;
	//链表长度不确定，使用动态数组
	double * array;
	array = (double*)malloc(listItemCount(&list) * sizeof(double));
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		array[i] = pnode->singer.averageScore;
		pnode = pnode->next;
	}

	pnode = list;
	//排序

	BubbleSort(array, listItemCount(&list));

	pnode = list;
	printf("按平均分排序：\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"编号", "姓名", "评委打分", "总分", "平均分");
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		for (size_t j = 0; j < listItemCount(&list); j++)
		{
			if (array[i] == pnode->singer.averageScore)
			{
				//输出当前节点的选手信息
				printf("%-2d\t%-8s", pnode->singer.num, pnode->singer.name);
				for (size_t c = 0; c < 10; c++)
				{
					printf("%-4d", pnode->singer.score[c]);
				}
				printf("%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);
			}
			pnode = pnode->next;
		}
		pnode = list;
	}
	//释放内存
	free(array);
	return;
}
//给inAverageOrder()用的，因为类型不兼容
void BubbleSort(double *num, int n)
{
	int i = 0;
	double temp = 0;
	bool swapped = true;
	do
	{
		swapped = false;
		for (size_t i = 0; i < n - 1; i++)
		{
			if (num[i] < num[i + 1])
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