
#include"head.h"
/*
*���������Լ��ֲ���������
*/
void showlist(Singer singer);

List list;
Singer temp;

void inputInfo()
{
	int i = 1;
	char ch;
	FILE * fp;
	if (check())
	{

		system("cls");

		/*��ʼ��*/
		initializeList(&list);
		if (listIsFull(&list))
		{
			fprintf(stderr, "No memory available! Bye!\n");
			exit(1);
		}

		/*�Ѽ����洢������Ϣ*/
		//printf("������ѡ�ֱ�ţ�");
		while (1)
		{
			//���
			printf("��������Ϊ%d��ѡ����Ϣ:\n", i);
			temp.num = i;

			printf("������ѡ��������");
			scanf("%s", &temp.name);
     		while (getchar() != '\n')//scanf()���������������'\n',�����һ�ε���scanf()���Ӱ��
				continue;            //���������������
		
			printf("������ѡ���Ա�");
			scanf("%s", &temp.sex);
			while (getchar() != '\n')
				continue;
			
			printf("������ѡ�ֵ绰���룺");
			scanf("%s", &temp.phoneNum);
			while (getchar() != '\n')
				continue;
		
			if (addItem(temp, &list) == false)
			{
				fprintf(stderr, "Problem allocating memory!\n");
				break;
			}

			if (listIsFull(&list))
			{
				puts("The list is now full.\n");
				break;
			}

			printf("������һ��ѡ����Ϣ����q�˳�,�����������������");
			i = i + 1;
			//��q����Q�˳�
			ch = getchar();
			if (ch == 'q')
			{
				return;
			}
			while (getchar() != '\n')
				continue;

		}
		
		/*��ʾ*/
		system("cls");
		if (listIsEmpty(&list))
		{
			printf("û��������Ϣ��\n");
		}
		else
		{
			printf("����������Ϣ��\n");
			printf("%-2s\t%-8s%-2s\t%-8s\n","���","����","�Ա�","�绰����");
			traverse(&list, showlist);
		}
		printf("��һ��������%d��ѡ����Ϣ��\n", listItemCount(&list));
		
		/*�������˵�*/
		printf("���س����������˵�\n");
		while (getchar() != '\n')
			continue;

		return;
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}
}


void showlist(Singer singer)
{
	printf("%-2d\t%-8s%-2s\t%-8s\n",
		singer.num, singer.name, singer.sex, singer.phoneNum);
}