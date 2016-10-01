
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
	*如果没有DATA文件，创建DATA文件并在passWord[]中写入初始密码“123456”
	*创建DATA文件失败则报错
	*如果有则把密码写到passWord[]中备用
	*/
	fp = fopen("DATA", "r");
	if (NULL == fp)
	{
		fp = fopen("DATA", "w+");
		if (NULL != fp)
		{
     		fprintf(fp, "123456");//fprintf()这个大坑比，必须fclose之后才能把数据写入文件
			fclose(fp);           //debug俩小时就为了个这，尼玛
			
			fp = fopen("DATA", "r+");
			fscanf(fp, "%s", passWord); //读取到passWord[]中
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
			puts(passWord);//检验数组是否正确读入密码,正式版要把这句去了
			fclose(fp);
		}
	}
	
	/*
	*密码检验，通过后显示修改密码选项，通不过返回菜单
	*/
	printf("请输入密码(第一次使用本功能请输入初始密码)：");
	scanf("%s", currentWord);
	
	/*
	*截去输入中的\n,以免影响之后的输入
	*/
	while ((i = getchar()) != '\n')
		;
	
	while (0 != strcmp(passWord, currentWord))  //strcmp(str1,str2)比较两个字符串，相等返回1，
	{                                           //str1<str2返回负数，str1>str2返回正数
		printf("密码错误！\n");
		Sleep(3000);
		return;
	}
	
	printf("修改当前密码？（Y/N）\n");
	scanf("%c", &ch);
	while ((i = getchar()) != '\n')
		;

	switch (ch)
	{
	case 'Y':changeWord(); break;
	case 'N':return; break;
	default:printf("Y确定，N退出！\n");
		break;
	}

	getchar();
}

/*
*修改密码功能函数
*要求输入两次，相同则修改成功，不同则重新要求输入
*/
void changeWord()
{
	FILE * fp;
	char firstNewWord[20] = { '\0' };
	char secondNewWord[20] = { '\0' };
	do
	{
		system("cls");
		printf("请输入新密码：");
		scanf("%s", firstNewWord);
		printf("请再次输入新密码：");
		scanf("%s", secondNewWord);
	} while (0 != strcmp(firstNewWord, secondNewWord));
	fp = fopen("DATA", "w+");
	if (NULL != fp)
	{
		fprintf(fp, "%s", firstNewWord);
		fclose(fp);
		printf("修改成功！\n");
		Sleep(3000);
	}
	else
	{
		printf("修改失败！\n");
		Sleep(3000);
		exit(EXIT_FAILURE);
	}
	return;
}
