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
		{                   //如果文件不存在,创建文件并写入
			fp = fopen("Doc.txt", "a+");
			if (NULL == fp)
			{
				exit(EXIT_FAILURE);
			}
			else
			{
				//显示写入数据
				printf("这是写入的信息：\n");
				printf("%-2s\t%-8s%-2s\t%-8s\n", "编号", "姓名", "性别", "电话号码");
				traverse(&pnode, showlist);
				//在文件里写入各栏标题
				fprintf(fp, "%-2s\t%-8s%-2s\t%-8s\n", "编号", "姓名", "性别", "电话号码");
				//循环写入数据
				while (pnode != NULL)
				{
					fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n",
						pnode->singer.num,pnode->singer.name,pnode->singer.sex,pnode->singer.phoneNum);
					pnode = pnode->next;
				}
				fclose(fp);
				printf("数据写入成功.\n");
				Sleep(3000);
				exit;
			}
		}
		else
		{
			//文件存在，说明之前创建过,直接在文件中内容尾部添加数据
			printf("这是写入的信息：\n");
			printf("%-2s\t%-8s%-2s\t%-8s\n", "编号", "姓名", "性别", "电话号码");
			traverse(&pnode, showlist);
			while (pnode != NULL)
			{
				fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n",
					pnode->singer.num, pnode->singer.name, pnode->singer.sex, pnode->singer.phoneNum);
				pnode = pnode->next;
			}
			fclose(fp);
			printf("数据写入成功!\n");
			exit;
		}
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}
}

