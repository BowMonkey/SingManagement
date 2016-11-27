
#include"head.h"

/*
*函数引用以及局部函数定义
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
		{                   //如果文件不存在,创建文件并写入
			fp = fopen("Doc.txt", "a+");
			if (NULL == fp)
			{
				exit(EXIT_FAILURE);
			}
			else
			{
				//显示写入数据
				showList(pnode);

				//在文件里写入各栏标题
				fprintf(fp, "%-2s\t%-8s%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n", "编号", "姓名", "性别", "电话号码","评委打分", "总分", "平均分");
				//循环写入数据
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
				printf("数据写入成功.\n");
				Sleep(3000);
				return;
			}
		}
		else
		{
			//文件存在，说明之前创建过,直接在文件中内容尾部添加数据
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
			printf("数据写入成功!\n");
			return;
		}
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}
}

