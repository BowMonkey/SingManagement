#include"head.h"

/*
�ֲ���������
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
		printf("û��������Ϣ��\n");
		Sleep(3000);
		return;
	}
	else
	{
		printf("��ѡ��Ҫ��ѯ��ѡ�ֱ�ţ�");
		scanf("%d", &num);
	rechoose:
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
		while ((i = getchar()) != '\n')
			;
		if (numExist)
		{
			//�ҵ���Ӧ��ŵĽڵ�
			system("cls");
			while (NULL != pnode)
			{
				if (pnode->singer.num == num)
				{
					printf("%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n",
						"���", "����", "��ί���", "�ܷ�", "ƽ����");
					printf("%-2d\t%-8s", pnode->singer.num, pnode->singer.name);

					for (size_t i = 0; i < 10; i++)
					{
						printf("%-4d", pnode->singer.score[i]);
					}
					printf("%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);
					printf("���س��˳���");
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
			printf("��Ų����ڣ����������룺");
			scanf("%d", &num);
			goto rechoose;
		}
	}
}

