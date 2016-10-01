
#include "head.h"

void password(void)
{
	FILE * fp;
	int i = 0;
	char passWord[40];
	char currentWord[40];

	system("cls");
	
	/*
	*如果没有DATA文件，创建DATA文件并写入初始化密码“123456”
	*创建DATA文件失败则报错
	*如果有则把密码写到passWord[]中备用
	*/
	fp = fopen("DATA", "r");
	if (NULL == fp)
	{
		fp = fopen("DATA", "w+");
		if (NULL != fp)
		{
     		fprintf(fp, "123456");      //有问题，先略过。不能初始化密码啊混蛋
			printf("已初始化密码\n");
			fclose(fp);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		while (fscanf(fp, "%s", passWord) == 1)
		{
			puts(passWord);
		}
			
		fclose(fp);
	}
	
	

	getchar();



}