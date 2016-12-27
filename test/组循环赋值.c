#include <stdio.h>

int main(void)
{
	char a[10];
	char b[10];
	printf("输入数字：");
	scanf("%s", &a);
	sscanf(a, "%[1-9]",&b);
	printf("%d", b);
	getchar();
	/*int num[10];
	int i = 10;
	printf("num大小：%d\n", sizeof(num)/sizeof(int));
	printf("赋值之前的初始值\n");
	for (size_t i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("num[%d]%d\n",i, num[i]);
	}
	printf("为num循环赋值\n");
	for (size_t i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		scanf("%d", &num[i]);
	}
	for (size_t i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("num循环赋值后的值\n%d\n", num[i]);
	}*/
	return 0;
}