#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//void Bubble_Sort(int * num);
int main(void)
{
	FILE * fp;
	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{                   //如果文件不存在,创建文件并写入
		fp = fopen("Doc.txt", "a+");
		if (NULL == fp)
		{
			printf("失败1");
		}
		else
		{

			//在文件里写入各栏标题
			fprintf(fp, "%-2s\t%-8s%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n", "编号", "姓名", "性别", "电话号码", "评委打分", "总分", "平均分");
			
			fclose(fp);
			printf("数据写入成功.\n");
			getchar();
			return;
		}
	}
	else
	{
		//文件存在，说明之前创建过,直接在文件中内容尾部添加数据
		fclose(fp);
		fp = NULL;
		fp = fopen("Doc.txt", "a+");
		fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n", "15", "姓名", "性别", "1845454545");
		fclose(fp);
		printf("数据写入成功!\n");
		return;
	}
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