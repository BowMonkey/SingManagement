
#include "head.h"

void password(void)
{
	FILE * fp;
	int i = 0;
	char passWord[40];
	char currentWord[40];

	system("cls");
	
	/*
	*���û��DATA�ļ�������DATA�ļ���д���ʼ�����롰123456��
	*����DATA�ļ�ʧ���򱨴�
	*������������д��passWord[]�б���
	*/
	fp = fopen("DATA", "r");
	if (NULL == fp)
	{
		fp = fopen("DATA", "w+");
		if (NULL != fp)
		{
     		fprintf(fp, "123456");      //�����⣬���Թ������ܳ�ʼ�����밡�쵰
			printf("�ѳ�ʼ������\n");
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