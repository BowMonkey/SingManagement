
#include"head.h"

/*
*���������Լ��ֲ���������
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
		printf("û��������Ϣ��\n");
		Sleep(3000);
		return;
	}
	else if (list->singer.totalScore == 0)
	{
		printf("���޷�����Ϣ��\n");
		Sleep(3000);
		return;
	}
	else
	{
		//printf("����������Ϣ��\n");
		//showList(list);

	rechoose:
		printf("һ�������˳����ʾ\n");
		printf("�������ܷ�˳����ʾ\n");
		printf("������ƽ����˳����ʾ\n");
		printf("��ѡ������ʽ��");
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
		default:printf("������1��2����3��\n");
			goto rechoose;
			break;
		}
	}

	printf("���س��˳���");
	while ((i = getchar()) != '\n')
		;
	return;
}


//�����ִܷ�С������ʾ
void inTotalOrder(Node *node)
{
	int i, j, c;
	Node *pnode = node;
	//�����Ȳ�ȷ����ʹ�ö�̬����
	int * array;
	array = (int*)malloc(listItemCount(&list) * sizeof(int));
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		array[i] = pnode->singer.totalScore;
		pnode = pnode->next;
	}

	pnode = list;
	//����
	Bubble_Sort(array, listItemCount(&list));

	pnode = list;
	printf("���ܷ�����\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"���", "����", "��ί���", "�ܷ�", "ƽ����");
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		for (size_t j = 0; j < listItemCount(&list); j++)
		{
			if (array[i] == pnode->singer.totalScore)
			{
				//�����ǰ�ڵ��ѡ����Ϣ
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
	//�ͷ��ڴ�
	free(array);
	return;
}

/*���������inTotalOrder()����һ������������ɹ��з�����ͨ�����ݲ�����ʵ�ֶԲ�ͬ��������*/
//����ƽ���ִ�С������ʾ
void inAverageOrder(Node *node)
{
	int i, j, c;
	Node *pnode = node;
	//�����Ȳ�ȷ����ʹ�ö�̬����
	double * array;
	array = (double*)malloc(listItemCount(&list) * sizeof(double));
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		array[i] = pnode->singer.averageScore;
		pnode = pnode->next;
	}

	pnode = list;
	//����

	BubbleSort(array, listItemCount(&list));

	pnode = list;
	printf("��ƽ��������\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"���", "����", "��ί���", "�ܷ�", "ƽ����");
	for (size_t i = 0; i < listItemCount(&list); i++)
	{
		for (size_t j = 0; j < listItemCount(&list); j++)
		{
			if (array[i] == pnode->singer.averageScore)
			{
				//�����ǰ�ڵ��ѡ����Ϣ
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
	//�ͷ��ڴ�
	free(array);
	return;
}
//��inAverageOrder()�õģ���Ϊ���Ͳ�����
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