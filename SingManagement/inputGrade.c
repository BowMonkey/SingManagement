#include"head.h"

void inputGrade(void)
{
	int i;

	i = check();
	if (i == 1)
	{
		//此处为本功能的具体实现内容
	}
	else
	{
		printf("密码错误！\n");
		Sleep(3000);
	}
	getchar();
}