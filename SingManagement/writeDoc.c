
#include"head.h"

/*
*���������Լ��ֲ���������
*/
extern List list;
extern void showList(Node *node);

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
				showList(pnode);

				//���ļ���д���������
				fprintf(fp, "%-2s\t%-8s%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n", "���", "����", "�Ա�", "�绰����","��ί���", "�ܷ�", "ƽ����");
				//ѭ��д������
				while (NULL != pnode)
				{
					fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n",
						pnode->singer.num, pnode->singer.name, pnode->singer.sex, pnode->singer.phoneNum);
					for (size_t i = 0; i < 10; i++)
					{
						fprintf(fp, "%-4d", pnode->singer.score[i]);
					}
					fprintf(fp, "%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);

					pnode = pnode->next;
				}
				fclose(fp);
				printf("����д��ɹ�.\n");
				Sleep(3000);
				return;
			}
		}
		else
		{
			//�ļ����ڣ�˵��֮ǰ������,ֱ�����ļ�������β���������
			showList(pnode);
			while (NULL != pnode)
			{
				fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n",
					pnode->singer.num, pnode->singer.name, pnode->singer.sex, pnode->singer.phoneNum);
				for (size_t i = 0; i < 10; i++)
				{
					fprintf(fp, "%-4d", pnode->singer.score[i]);
				}
				fprintf(fp, "%10d\t%10f\n", pnode->singer.totalScore, pnode->singer.averageScore);

				pnode = pnode->next;
			}
			fclose(fp);
			printf("����д��ɹ�!\n");
			return;
		}
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}
}

