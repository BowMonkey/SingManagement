
#include"head.h"

/*
*�����Լ���������
*/
extern List list;
extern void showList(Node *node);
extern void Bubble_Sort(int * num, int n);


void addInfo()
{
	int i;
	int numCount = 0;
	int sum = 0;
	char ch;
	int array[10];
	double average = 0;
	Node *pnode = list;
	Singer newSinger;


	if (check())
	{
		if (listIsEmpty(&list))
		{
			printf("��û��������Ϣ,��ѡ����һ�������룡\n");
			Sleep(3000);
			return;
		}
		else
		{
			while (pnode->next != NULL)
			{
				pnode = pnode->next;
			}
			numCount=pnode->singer.num;
			pnode = list;

		reAdd:
			system("cls");
			//showList(pnode);
			printf("����ӱ��Ϊ%d��ѡ����Ϣ��\n", numCount+1);
			newSinger.num = numCount + 1;
			printf("������Ҫ��ӵ�ѡ��������");
			scanf("%s", &newSinger.name);
			printf("������Ҫ��ӵ�ѡ���Ա�");
			scanf("%s", &newSinger.sex);
			printf("������Ҫ��ӵ�ѡ�ֵ绰���룺");
			scanf("%s", &newSinger.phoneNum);
			printf("������Ҫ��ӵ�ѡ�ֵ���ί���֣�\n");
			for (size_t i = 0; i < 10; i++)
			{
			re:
				printf("��%d��ί�Ĵ�֣�", (i + 1));
				scanf("%d", &newSinger.score[i]);
				/*���Ʒ�����Χ1-10��������������*/
				if (newSinger.score[i] < 0 || newSinger.score[i] > 10)
				{
					printf("ѡ�ֵ÷ֳ����涨��Χ��������0~10֮������֣�\n");
					goto re;
				}
			}
			//�����ܷ�
			newSinger.totalScore = 0;
			for (size_t i = 0; i < 10; i++)
			{
				newSinger.totalScore += newSinger.score[i];
			}
			//����ƽ����
			for (size_t i = 0; i < (sizeof(array) / sizeof(int)); i++)
			{
				array[i] = newSinger.score[i];
			}
			//����
			Bubble_Sort(array, sizeof(array) / sizeof(int));

			for (size_t i = 1; i < (sizeof(array) / sizeof(int)) - 2; i++)
			{
				sum += array[i];
			}
			average = sum / 8.0;
			newSinger.averageScore = average;
			//ʹ��addItem(Singer singer, List * plist);�ӿ����singer������
			if (addItem(newSinger, &pnode))
			{
				printf("�����Ϣ�ɹ���\n");
				system("cls");
				showList(pnode);
				printf("���������Ϣ��(y/n)\n");
			rechoose:
				while ((i = getchar()) != '\n')
					;
				scanf("%c", &ch);
				switch (ch)
				{
				case 'y':numCount++;
					goto reAdd;
					
				case 'n':return;
				default:printf("yȷ����n�˳���\n");
					goto rechoose;
				}
			}
			else
			{
				printf("�����Ϣʧ�ܣ�\n");
				Sleep(3000);
				return;
			}

		}
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}

}