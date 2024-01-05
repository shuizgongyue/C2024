#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string>

//void maopao(int* arr, int len)
//{
//	int i = 0;
//	for (i = 0; i <= len; i++)
//	{
//		int j = 0;
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			int tmp = 0;
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}

void maopao(int* arr, int len)
{
	int i = 0;
	for (i = 0; i <= len; i++)
	{
			int tmp = 0;
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
	}
}
//int main()
//{
//	int arr[] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
//	int len = sizeof(arr)/sizeof(arr[0]); // 长度
//	int i = 0;
//	printf("arr: ");
//	for ( i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	maopao(arr,len);
//	printf("arr: ");
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//int main()
//{
//	double x = 2.5;
//	double y = 4.7;
//	int a = 7;
//	double z = x + a % 3 * (int)(x + y) % 2 / 4;
//	printf("%f", z);           // 2.5
//	return 0;
// }

//  1
	//void my_strcpy(char* arr1, char* arr)
	//{
	//	while (*arr!='\0')
	//	{
	//		*arr1 = *arr;
	//		arr1++;
	//		arr++;
	//	}
	//}
// 2
	//void my_strcpy(char* arr1, char* arr)
	//{
	//	while (*arr != '\0')
	//	{
	//		*arr1++ = *arr++;
	//	}
	//	*arr1 = *arr; // \0
	//}
// 3
	//void my_strcpy(char* arr1, char* arr)
	//{
	//	while (*arr1++ = *arr++)
	//	{
	//	}
	//}
// 4
#include <assert.h>
	void my_strcpy(char* arr1, char* arr)
	{
		// 加入断言 检查是否有问题 有的话就抛出错误
		assert(arr1 != NULL); // 如果 传参的时候传的 空值那么就会报错;
		assert(arr != NULL);
		while (*arr1++ = *arr++)
		{

		}
	}
// 5
	void my_strcpy(char* arr1, const char* arr) // 使用 const 使其拥有常数性 从而不能被改变
	{
		// 加入断言 检查是否有问题 有的话就抛出错误
		assert(arr1 != NULL); // 如果 传参的时候传的 空值那么就会报错; 
		assert(arr != NULL);
		//while (*arr++ = *arr1++) 该写法会报错
		while (*arr1++ = *arr++)
		{

		}
	}

	// const char* arr 表示 *arr不能被修改  ；
	// char* const arr 表示 arr不能被修改  ； 两者用法有根本的区别
			//int main()
			//{
			//	char arr[] = "ssbnfjasbf";
			//	char arr1[15] = "0";
			//	// strcpy(arr1, arr);  定义函数实现该功能；
			//	//printf("%c", arr1[4]);
			//	my_strcpy(arr1, arr);
			//	//my_strcpy(arr1, NULL);
	
			//	return 0;
			//}

// 完成冒泡排序;
void mp(int* arr,int len)
{
	//第一次对比后需要排序 len - 1 趟
	for (int i = 0; i < len - 1; i++)
	{
		//第一次对比完后 一个元素已经被放到正确的位置 假设总共有 10 个元素 第一次后 还剩 8个元素需要对比
		for (int j = 0; j < len - 1 - i ; j++)
		{
			if (arr[j] > arr[j + 1]) // 前两个元素对比
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//int main()
//{
//	int arr[] = {10,9,8,7,6,5,4,3,2,1,0 }; //使其升序
//	int len = sizeof(arr) / sizeof(arr[0]);
//	mp(arr,len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

int my_tu(int* arr,int len, int a)
{
	// 左右下标
	int z = 0;
	int y = len - 1;
	
	while (z<=y)
	{
		int zj = (y + z) / 2;
		if (arr[zj] > a)
			y = zj - 1;
		else if (arr[zj] < a)
			z = zj + 1;
		else
			return zj;
	}
	return -1;
}

// ======  写一个函数实现二分查找  加入找到了给定数 那么返回这个数的下标;
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a = 0;
	scanf("%d", &a);	// 接受查找的值;
	int len = sizeof(arr) / sizeof(arr[0]);
	int jg=my_tu(arr,len,a);
	if (jg != -1)
		printf("找到了下标为：%d ", jg);
	else
		printf("没有找到");
	return 0;
}