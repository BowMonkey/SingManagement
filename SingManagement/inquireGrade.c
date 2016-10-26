#include"head.h"

/*
局部函数定义
*/
extern List list;
extern Singer temp;
void searchFile(int num);
void searchTable(int num);

void inquireGrade()
{
	int i, j;

	system("cls");
	printf("请输入要查询的选手编号：");
	scanf("%d", &i);
	
rechoose:
	printf("一：从已生成的数据文件查询\n");
	printf("二：从链表中查询\n");
	printf("请选择查询源：");
	
	scanf("%d", &j);

	switch (j)
	{
	case 1:searchFile(i); break;
	case 2:searchTable(i); break;
	default:printf("请输入1或者2！\n");
		goto rechoose;
		break;
	}

}

/*从Doc.txt文件中查询相应编号信息*/
void searchFile(int num)
{
	FILE * fp;
	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{
		printf("文件Doc.txt不存在！请选择其他方式查询！\n");
		Sleep(3000);
		exit;
	}
	else
	{
		//从文件读取数据到新链表——》查询
		;
	}
}


/*从链表中查询相应信息*/
void searchTable(int num)
{

}