
#include "head.h"

void password(void)
{
	FILE * fp;
	int i = 0;
	int passWord[10] = { '\0' };
	/*
	*���û��DATA�ļ�������DATA�ļ���д���ʼ�����롰000000��
	*����DATA�ļ�ʧ���򱨴�
	*������������д��passWord[]�б���
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