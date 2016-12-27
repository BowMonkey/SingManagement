
#include"head.h"
/*
*函数引用以及局部函数定义
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

		/*初始化*/
		initializeList(&list);
		if (listIsFull(&list))
		{
			fprintf(stderr, "No memory available! Bye!\n");
			exit(1);
		}

		/*搜集并存储歌手信息*/
		//printf("请输入选手编号：");
		while (1)
		{
			//编号
			printf("请输入编号为%d的选手信息:\n", i);
			temp.num = i;

			printf("请输入选手姓名：");
			scanf("%s", &temp.name);
     		while (getchar() != '\n')//scanf()不会接收输入最后的'\n',会对下一次调用scanf()造成影响
				continue;            //所以用这个来消除
		
			printf("请输入选手性别：");
			scanf("%s", &temp.sex);
			while (getchar() != '\n')
				continue;
			
			printf("请输入选手电话号码：");
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

			printf("输入下一个选手信息（按q退出,按其他任意键继续）");
			i = i + 1;
			//按q或者Q退出
			ch = getchar();
			if (ch == 'q')
			{
				return;
			}
			while (getchar() != '\n')
				continue;

		}
		
		/*显示*/
		system("cls");
		if (listIsEmpty(&list))
		{
			printf("没有输入信息！\n");
		}
		else
		{
			printf("这是输入信息：\n");
			printf("%-2s\t%-8s%-2s\t%-8s\n","编号","姓名","性别","电话号码");
			traverse(&list, showlist);
		}
		printf("你一共输入了%d个选手信息。\n", listItemCount(&list));
		
		/*返回主菜单*/
		printf("按回车键返回主菜单\n");
		while (getchar() != '\n')
			continue;

		return;
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}
}


void showlist(Singer singer)
{
	printf("%-2d\t%-8s%-2s\t%-8s\n",
		singer.num, singer.name, singer.sex, singer.phoneNum);
}