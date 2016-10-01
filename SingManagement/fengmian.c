
#include"head.h"

int fengmian(void)
{
	int i;
	/*
	*显示封面字符画3秒
	*/
	system("type fengmian01.txt\n");
	Sleep(3000);
	system("cls");
	
	/*
	*菜单
	*/
	system("type fengmian02.txt\n");
	gotoxy(65, 18);
	printf("歌手比赛成绩管理系统");
	gotoxy(65, 30);
	printf("功能一：输入选手数据");
	gotoxy(65, 32);
	printf("功能二：评委打分");
	gotoxy(65, 34);
	printf("功能三：成绩排序");
	gotoxy(65, 36);
	printf("功能四：数据查询");
	gotoxy(65, 38);
	printf("功能五：追加数据");
	gotoxy(65, 40);
	printf("功能六：生成数据文件");
	gotoxy(65, 42);
	printf("功能七：退出系统");
	gotoxy(115, 49);
	Ptime();

	gotoxy(60, 45);
	printf("请选择功能编号：");
	scanf("%d", &i);
	
	return i;

}

/*显示当前时间的函数*/
void Ptime(void)
{
	char * wday[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
	time_t t;
	struct tm *p;
	t = time(NULL);
	p = gmtime(&t);
	printf("%d年%2d月%2d日", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %s ", wday[p->tm_wday]);
	printf("%02d:%02d:%02d\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);
}

/*移动光标到指定位置*/
void gotoxy(int x, int y)
{
	COORD coord; // coordinates  
	coord.X = x; coord.Y = y; // X and Y coordinates  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates  
}