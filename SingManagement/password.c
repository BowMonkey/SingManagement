
#include "head.h"

void password()
{
	FILE * fp;
	int i = 0;
	char ch;
	char passWord[20] = { '\0' };
	char currentWord[20] = { '\0' };

	system("cls");
	
	/*
	*���û��DATA�ļ�������DATA�ļ�����passWord[]��д���ʼ���롰123456��
	*����DATA�ļ�ʧ���򱨴�
	*������������д��passWord[]�б���
	*/
	fp = fopen("DATA", "r");
	if (NULL == fp)
	{
		fp = fopen("DATA", "w+");
		if (NULL != fp)
		{
     		fprintf(fp, "123456");//fprintf()�����ӱȣ�����fclose֮����ܰ�����д���ļ�
			fclose(fp);           //debug��Сʱ��Ϊ�˸��⣬����
			
			fp = fopen("DATA", "r+");
			fscanf(fp, "%s", passWord); //��ȡ��passWord[]��
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
			puts(passWord);//���������Ƿ���ȷ��������,��ʽ��Ҫ�����ȥ��
			fclose(fp);
		}
	}
	
	/*
	*������飬ͨ������ʾ�޸�����ѡ�ͨ�������ز˵�
	*/
	printf("����������(��һ��ʹ�ñ������������ʼ����)��");
	scanf("%s", currentWord);
	
	/*
	*��ȥ�����е�\n,����Ӱ��֮�������
	*/
	while ((i = getchar()) != '\n')
		;
	
	while (0 != strcmp(passWord, currentWord))  //strcmp(str1,str2)�Ƚ������ַ�������ȷ���1��
	{                                           //str1<str2���ظ�����str1>str2��������
		printf("�������\n");
		Sleep(3000);
		return;
	}
	
	printf("�޸ĵ�ǰ���룿��Y/N��\n");
	scanf("%c", &ch);
	while ((i = getchar()) != '\n')
		;

	switch (ch)
	{
	case 'Y':changeWord(); break;
	case 'N':return; break;
	default:printf("Yȷ����N�˳���\n");
		break;
	}

	getchar();
}

/*
*�޸����빦�ܺ���
*Ҫ���������Σ���ͬ���޸ĳɹ�����ͬ������Ҫ������
*/
void changeWord()
{
	FILE * fp;
	char firstNewWord[20] = { '\0' };
	char secondNewWord[20] = { '\0' };
	do
	{
		system("cls");
		printf("�����������룺");
		scanf("%s", firstNewWord);
		printf("���ٴ����������룺");
		scanf("%s", secondNewWord);
	} while (0 != strcmp(firstNewWord, secondNewWord));
	fp = fopen("DATA", "w+");
	if (NULL != fp)
	{
		fprintf(fp, "%s", firstNewWord);
		fclose(fp);
		printf("�޸ĳɹ���\n");
		Sleep(3000);
	}
	else
	{
		printf("�޸�ʧ�ܣ�\n");
		Sleep(3000);
		exit(EXIT_FAILURE);
	}
	return;
}
