#include <stdio.h>

int main(void)
{
	char a[10];
	char b[10];
	printf("�������֣�");
	scanf("%s", &a);
	sscanf(a, "%[1-9]",&b);
	printf("%d", b);
	getchar();
	/*int num[10];
	int i = 10;
	printf("num��С��%d\n", sizeof(num)/sizeof(int));
	printf("��ֵ֮ǰ�ĳ�ʼֵ\n");
	for (size_t i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("num[%d]%d\n",i, num[i]);
	}
	printf("Ϊnumѭ����ֵ\n");
	for (size_t i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		scanf("%d", &num[i]);
	}
	for (size_t i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		printf("numѭ����ֵ���ֵ\n%d\n", num[i]);
	}*/
	return 0;
}