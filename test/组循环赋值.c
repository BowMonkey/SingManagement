#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//void Bubble_Sort(int * num);
int main(void)
{
	FILE * fp;
	fp = fopen("Doc.txt", "r");
	if (NULL == fp)
	{                   //����ļ�������,�����ļ���д��
		fp = fopen("Doc.txt", "a+");
		if (NULL == fp)
		{
			printf("ʧ��1");
		}
		else
		{

			//���ļ���д���������
			fprintf(fp, "%-2s\t%-8s%-2s\t%-8s\t\t%-4s\t\t\t%-10s%-10s\n", "���", "����", "�Ա�", "�绰����", "��ί���", "�ܷ�", "ƽ����");
			
			fclose(fp);
			printf("����д��ɹ�.\n");
			getchar();
			return;
		}
	}
	else
	{
		//�ļ����ڣ�˵��֮ǰ������,ֱ�����ļ�������β���������
		fclose(fp);
		fp = NULL;
		fp = fopen("Doc.txt", "a+");
		fprintf(fp, "%-2d\t%-8s%-2s\t%-8s\n", "15", "����", "�Ա�", "1845454545");
		fclose(fp);
		printf("����д��ɹ�!\n");
		return;
	}
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