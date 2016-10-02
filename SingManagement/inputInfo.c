
#include"head.h"

void showlist(Singer singer);

void inputInfo()
{
	int i;
	FILE * fp;
	if (check())
	{
		List list;
		Singer temp;

		system("cls");
		puts("����Ҫ��Ϊblalba(���س�����)");
		while (getchar() != '\n')
			continue;
		system("cls");

		/*��ʼ��*/
		initializeList(&list);
		if (listIsFull(&list))
		{
			fprintf(stderr, "No memory available! Bye!\n");
			exit(1);
		}

		/*�Ѽ����洢������Ϣ*/
		printf("������ѡ�ֱ�ţ�");
		while (scanf("%u", &temp.num) != NULL )
		{
			while (getchar() != '\n')
				continue;
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

			printf("������һ��ѡ�ֱ�ţ���q�˳�����");//Ҫ��ӱ���ظ��ļ�飡������
		}
		
		while (getchar() != '\n')
			continue;
		
		/*��ʾ*/
		system("cls");
		if (listIsEmpty(&list))
		{
			printf("û��������Ϣ��\n");
		}
		else
		{
			printf("����������Ϣ��\n");
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
	printf("��ţ�%d\t������%s\t�Ա�%s\t�绰��%s\n",
		singer.num, singer.name, singer.sex, singer.phoneNum);
}