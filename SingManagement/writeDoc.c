#include"head.h"


extern List list;
extern Singer temp;
extern void showlist(Singer singer);

void writeDoc()
{
	FILE * fp;
	Node * pnode = list;
	if (check())
	{
		fp = fopen("Doc.txt", "a+");
		if (NULL == fp)
		{                   //����ļ�������,�����ļ���д��
			fp = fopen("Doc.txt", "a+");
			if (NULL == fp)
			{
				exit(EXIT_FAILURE);
			}
			else
			{
				//��ʾд������
				printf("����д�����Ϣ��\n");
				printf("%-2s\t%-8s%-2s\t%-8s\n", "���", "����", "�Ա�", "�绰����");
				traverse(&pnode, showlist);
				//���ļ���д���������
				fprintf(fp, "%-2s\t%-8s%-2s\t%-8s\n", "���", "����", "�Ա�", "�绰����");
				//ѭ��д������
				while (pnode != NULL)
				{
					fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n",
						pnode->singer.num,pnode->singer.name,pnode->singer.sex,pnode->singer.phoneNum);
					pnode = pnode->next;
				}
				fclose(fp);
				printf("����д��ɹ�.\n");
				Sleep(3000);
				exit;
			}
		}
		else
		{
			//�ļ����ڣ�˵��֮ǰ������,ֱ�����ļ�������β���������
			printf("����д�����Ϣ��\n");
			printf("%-2s\t%-8s%-2s\t%-8s\n", "���", "����", "�Ա�", "�绰����");
			traverse(&pnode, showlist);
			while (pnode != NULL)
			{
				fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n",
					pnode->singer.num, pnode->singer.name, pnode->singer.sex, pnode->singer.phoneNum);
				pnode = pnode->next;
			}
			fclose(fp);
			printf("����д��ɹ�!\n");
			exit;
		}
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}
}

