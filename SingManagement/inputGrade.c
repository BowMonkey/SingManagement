
#include"head.h"

/*
*���������Լ��ֲ���������
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
			printf("��û������ѡ����Ϣ��\n");
			Sleep(3000);
			return;
		}
		else
		{
			/*����while�õ������⣬�Ժ�ģ�������
			*/
			//���while�����û�а����нڵ㸳ֵ�꣨�Ƿ�����ѡ�־�����֣�
			while (j <= listItemCount(&list))
			{
				system("cls");
				showList(list);
				printf("������Ҫ��ֵ�ѡ�ֱ�ţ�");
				scanf("%u", &num);
			rechoose:
				pnode = list;
				//����������Ƿ����,����numExit��Ϊtrue,����false
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
				//��������ѭ��֮��pnode�Ѳ�ָ������ʼλ�ã��������¸�ֵ
				pnode = list;

				if (numExist)
				{
					//�ҵ���Ӧ��ŵĽڵ�
					while (NULL != pnode)
					{
						if (pnode->singer.num == num)
							break;
						pnode = pnode->next;
					}

					inputScore(pnode);
					//��������ѭ��֮��pnode�Ѳ�ָ������ʼλ�ã��������¸�ֵ
					pnode = list;
					j++;
				}
				else
				{
					system("cls");
					showList(list);
					printf("��Ų����ڣ����������룺");
					scanf("%d", &num);
					goto rechoose;
				}
			}
		}
		system("cls");
		showList(list);
		printf("���з���������ϣ�");
		Sleep(3000);

		return;
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}
	getchar();
}


/*��ʾѡ�ֵ�ǰ������Ϣ*/
void showList(Node *node)
{
	Node * pnode = node;
	printf("��������ѡ����Ϣ��\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"���", "����", "��ί���", "�ܷ�", "ƽ����");
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


/*������ί��ĳһ��ѡ�ִ��*/
void inputScore(Node *pnode)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("��%d��ί�Ĵ�֣�", (i + 1));
		scanf("%d", &pnode->singer.score[i]);
	}
	for (i = 0; i < 10; i++)
	{
		pnode->singer.totalScore += pnode->singer.score[i];
	}
	pnode->singer.averageScore = averageScore(pnode);
}


/*���㲢����ƽ���ֺ���*/
double averageScore(Node *pnode)
{
	int i;
	int sum = 0;
	int array[10];//�½�array�����������򣬱���ԭʼ����
	//��������������鸳ֵ
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = pnode->singer.score[i];
	}
	//����
	Bubble_Sort(array,(sizeof(array)/sizeof(int)));
	//����ƽ����
	for (size_t i = 1; i <= 8; i++)
	{
		sum += array[i];
	}
	return (sum / 8);
}


//ð������
//ʹ��ǰ�Ƚ�������Ҫ���������ѭ�����Ƹ�һ���µ�����num
//�ٽ��½������������ݸ�������
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