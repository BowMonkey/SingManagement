#include"head.h"

void exitSys()
{
	int i;

	i = check();
	if (i == 1)
	{
		//�˴�Ϊ�����ܵľ���ʵ������
	}
	else
	{
		printf("�������\n");
		Sleep(3000);
	}
	getchar();
}