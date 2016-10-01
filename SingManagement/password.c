
#include "head.h"

void password(void)
{
	FILE * fp;
	int i = 0;
	int passWord[10] = { '\0' };
	/*
	*如果没有DATA文件，创建DATA文件并写入初始化密码“000000”
	*创建DATA文件失败则报错
	*如果有则把密码写到passWord[]中备用
	*/
	if (NULL == (fp = fopen("DATA","r")))
	{
		if (NULL == (fp = fopen("DATA", "w+")))
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(fp, "000000");
			fclose(fp);
		}
	}
	else
	{
		while (fscanf(fp, "%d", &passWord[i]) != EOF)
			i++;
	}
	for ( i = 0; i < 10; i++)
	{
		printf("%d", passWord[i]);
	}

	getchar();
}