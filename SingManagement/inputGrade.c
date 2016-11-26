
#include"head.h"

/*
*���������Լ��ֲ���������
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
			printf("��û������ѡ����Ϣ��\n");
			Sleep(3000);
			return;
		}
		else
		{
			//���while�����û�а����нڵ㸳ֵ�꣨�Ƿ�����ѡ�־�����֣�
			while (j <= listItemCount(&list))
			{
				system("cls");
				showList(list);
				printf("������Ҫ��ֵ�ѡ�ֱ�ţ�");
				scanf("%d", &i);
				//����������Ƿ񳬳���Χ
				while (i <= 0 || i>listItemCount(&list))
				{
					system("cls");
					showList(list);
					printf("��ų�����Χ�����������룺");
					scanf("%d", &i);
				}
				//�ҵ���Ӧ��ŵĽڵ�
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
void showList(Node *pnode)
{
	printf("��������ѡ����Ϣ��\n");
	printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
		"���", "����", "��ί���", "�ܷ�", "ƽ����");
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


/*������ί��ĳһ��ѡ�ִ��*/
void inputScore(Node *pnode)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("��%d��ί�Ĵ�֣�", (i + 1));
		scanf("%d", &pnode->singer.score[i]);
	}
	for ( i = 0; i < 10; i++)
	{
		pnode->singer.totalScore += pnode->singer.score[i];
	}
	pnode->singer.averageScore = averageScore(pnode);
}


/*���㲢����ƽ���ֺ���*/
double averageScore(Node *pnode)
{
	int i = 0;
	int temp = 0;
	int sum = 0;
	int array[10];//�½�array�����������򣬱���ԭʼ����
	bool swapped = true;
	for (size_t i = 0; i < 10; i++)
	{
		array[i] = pnode->singer.score[i];
	}
	//ð������score
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