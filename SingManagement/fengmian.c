
#include"head.h"

int fengmian(void)
{
	int i;
	/*
	*��ʾ�����ַ���3��
	*/
	system("type fengmian01.txt\n");
	Sleep(3000);
	system("cls");
	
	/*
	*�˵�
	*/
	system("type fengmian02.txt\n");
	gotoxy(65, 18);
	printf("���ֱ����ɼ�����ϵͳ");
	gotoxy(65, 30);
	printf("����һ������ѡ������");
	gotoxy(65, 32);
	printf("���ܶ�����ί���");
	gotoxy(65, 34);
	printf("���������ɼ�����");
	gotoxy(65, 36);
	printf("�����ģ����ݲ�ѯ");
	gotoxy(65, 38);
	printf("�����壺׷������");
	gotoxy(65, 40);
	printf("�����������������ļ�");
	gotoxy(65, 42);
	printf("�����ߣ��˳�ϵͳ");
	gotoxy(115, 49);
	Ptime();

	gotoxy(60, 45);
	printf("��ѡ���ܱ�ţ�");
	scanf("%d", &i);
	
	return i;

}

/*��ʾ��ǰʱ��ĺ���*/
void Ptime(void)
{
	char * wday[] = { "������", "����һ", "���ڶ�", "������", "������", "������", "������" };
	time_t t;
	struct tm *p;
	t = time(NULL);
	p = gmtime(&t);
	printf("%d��%2d��%2d��", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	printf(" %s ", wday[p->tm_wday]);
	printf("%02d:%02d:%02d\n", (8 + p->tm_hour), p->tm_min, p->tm_sec);
}

/*�ƶ���굽ָ��λ��*/
void gotoxy(int x, int y)
{
	COORD coord; // coordinates  
	coord.X = x; coord.Y = y; // X and Y coordinates  
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates  
}