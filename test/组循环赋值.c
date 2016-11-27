#include<stdio.h>
#include<stdbool.h>
void Bubble_Sort(int * num);
int main(void)
{

	int i = 0;

	int array[10] = { 4,45,12,1,1,23,123,231,23,5 };
	printf("%d", sizeof(array)/sizeof(int));
	//int array1[10];//新建array数组用来排序，保护原始数据

	//for (size_t i = 0; i < 10; i++)
	//{
	//	array1[i] = array[i];
	//}

	//Bubble_Sort(array1);
	//
	////显示排序后的数组
	//for (size_t i = 0; i < 10; i++)
	//{
	//	printf("%d  ",array1[i]);
	//}
	return 0;
}

////冒泡排序
////使用前先将链表中要排序的数据循环复制给一个新的数组num
////再将该数组名传递给本函数
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