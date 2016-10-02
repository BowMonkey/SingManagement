
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
		puts("输入要求为blalba(按回车继续)");
		while (getchar() != '\n')
			continue;
		system("cls");

		/*初始化*/
		initializeList(&list);
		if (listIsFull(&list))
		{
			fprintf(stderr, "No memory available! Bye!\n");
			exit(1);
		}

		/*搜集并存储歌手信息*/
		printf("请输入选手编号：");
		while (scanf("%u", &temp.num) != NULL )
		{
			while (getchar() != '\n')
				continue;
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

			printf("输入下一个选手编号（按q退出）：");//要添加编号重复的检查！！！！
		}
		
		while (getchar() != '\n')
			continue;
		
		/*显示*/
		system("cls");
		if (listIsEmpty(&list))
		{
			printf("没有输入信息！\n");
		}
		else
		{
			printf("这是输入信息：\n");
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
	printf("编号：%d\t姓名：%s\t性别：%s\t电话：%s\n",
		singer.num, singer.name, singer.sex, singer.phoneNum);
}