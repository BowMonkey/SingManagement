#include<stdio.h>
#include<stdbool.h>
void Bubble_Sort(int * num);
int main(void)
{

	int i = 0;

	int array[10] = { 4,45,12,1,1,23,123,231,23,5 };
	printf("%d", sizeof(array)/sizeof(int));
	//int array1[10];//�½�array�����������򣬱���ԭʼ����

	//for (size_t i = 0; i < 10; i++)
	//{
	//	array1[i] = array[i];
	//}

	//Bubble_Sort(array1);
	//
	////��ʾ����������
	//for (size_t i = 0; i < 10; i++)
	//{
	//	printf("%d  ",array1[i]);
	//}
	return 0;
}

////ð������
////ʹ��ǰ�Ƚ�������Ҫ���������ѭ�����Ƹ�һ���µ�����num
////�ٽ������������ݸ�������
//void Bubble_Sort(int * num)
//{
//	int i = 0;
//	int temp = 0;
//	bool swapped = true;
//	do
//	{
//		swapped = false;
//		for (size_t i = 0; i < 9; i++)
//		{
//			if (num[i]>num[i + 1])
//			{
//				temp = num[i];
//				num[i] = num[i + 1];
//				num[i + 1] = temp;
//				swapped = true;
//			}
//		}
//	} while (swapped);
//	return;
//}