
#include"head.h"

int main(void)
{
	/*
	*����̨��С��ʼ��
	*/
	system("mode con  cols=150 lines=50");
	
	switch (fengmian())
	{

	case 1:inputInfo(); break;
	case 2:inputGrade(); break;
	case 3:Rank(); break;
	case 4:inquireGrade(); break;
	case 5:addInfo(); break;
	case 6:writeDoc(); break;
	case 7:exitSys(); break;
	case 10:password(); break;

	default:printf("Error! Please enter the function number!\n"); break;
	}

	return 0;
}