#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>

using namespace std;

int CountArray[65536] = {0};  //定义计数数组，空间复杂度S(n)换时间复杂度T(n)


int Majority_Element(int* Array, int length)
{
		int ele = Array[0];
		CountArray[ele]++;
		int count = 1;
		//int time = 0;
		for (int i = 1; i < length; i++) 
		{
			if (ele == Array[i]) 
			{
				count++;
				CountArray[ele]++;
			}
			else 
			{
				count--;
				CountArray[Array[i]]++;
			}
			if (count == 0) 
			{
				ele = Array[i];
				count++;
			}
		}
		if (CountArray[ele] > length / 2)
			return ele;
		else
			return NULL;
		/*for (int i = 0; i < length; i++)
		{
			if (ele == Array[i])
				time++;
		}
		if (time > length / 2)
			return ele;
		else
			return NULL;*/

}

void main()
{
	int length;
	printf("Please input the length of your array:\n");
	scanf_s("%d", &length);
	//printf("%d", length);
	printf("Please input your array:(Number Should be Seperated Through Blanks or Enter!!!)\n");
	int* Array = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++)
	{
		scanf_s("%d", &Array[i]);
	}
	int res = Majority_Element(Array, length);
	if (res != NULL)
		printf("The majority element in this array is %d", res);
	else
		printf("There is no majority element in this array!");
	/*for (int i = 0; i < length; i++)
	{
		printf("%d", Array[i]);
	}*/
	free(Array);
}