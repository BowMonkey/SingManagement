
#include"head.h"

int check()
{
	FILE * fp;
	int i;
	char passWord[20] = { '\0' };
	char currentWord[20] = { '\0' };

	system("cls");

	/*
	*若DATA文件存在则读取密码至passWord[],准备进行比较
	*若不存在则创建DATA文件并初始化密码为123456
	*(是的，这部分代码就是直接复制password.c的=。=)
	*/
	fp = fopen("DATA", "r");
	if (NULL == fp)
	{
		fp = fopen("DATA", "w+");
		if (NULL != fp)
		{
			fprintf(fp, "123456");
			fclose(fp);          

			fp = fopen("DATA", "r+");
			fscanf(fp, "%s", passWord);
			fclose(fp);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fscanf(fp, "%s", passWord);
		fclose(fp);
	}

	printf("请输入密码：");
	scanf("%s", currentWord);
	
	while ((i = getchar()) != '\n')
		;

	if (0 != strcmp(passWord, currentWord))
	{
		return false;
	}
	else
	{
		return true;
	}
}