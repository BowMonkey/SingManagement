
#include"head.h"

int check()
{
	FILE * fp;
	int i;
	char passWord[20] = { '\0' };
	char currentWord[20] = { '\0' };

	system("cls");

	/*
	*��DATA�ļ��������ȡ������passWord[],׼�����бȽ�
	*���������򴴽�DATA�ļ�����ʼ������Ϊ123456
	*(�ǵģ��ⲿ�ִ������ֱ�Ӹ���password.c��=��=)
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

	printf("���������룺");
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