#include<stdio.h>
#include<stdbool.h>
int main(void)
{

	int i = 0;
	int temp;
	bool swapped = true;
	int array[10] = { 4,45,12,1,1,23,123,231,23,5 };
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	//Ã°ÅÝÅÅÐòscore
	do
	{
		swapped = false;
		for (size_t i = 0; i < 9; i++)
		{
			if (array[i]>array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d\t",array[i]);
	}
	return 0;
}