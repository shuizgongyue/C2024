#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

typedef struct XSxx
{
	char name[20];
	int age;
}XS;
int my_cmp_int( void* s1, void* s2)
{
	return (*(int*)(s1)) - (*(int*)(s2));     // 整形的比较算法
}

int my_cmp_struct_Age( void* a1,  void* a2)
{
	return ((struct XSxx*)a1)->age - ((struct XSxx*)a2)->age; // 对结构体元素的比较算法
}

int cmp_struct_name( void* e1, void* e2)
{
	//名字的比较就是比较字符串
	//字符串比较不能直接用 > < = 来比较； 应该使用函数strcmp来进行;
	return strcmp(((struct XSxx*)e1)->name, ((struct XSxx*)e2)->name); // 对结构体元素 名字的排序
}
void print(char* best1,char* best2,int width)   //交换打印
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *best1;
		*best1 = *best2;
		*best2 = tmp;
		best1++;
		best2++;
	}
}
void my_qsort(void* best, int sz, int width, int (*cmp)( void* e1, void* e2))
{
	// 冒泡排序 实现
	int i = 0, j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)best + j * width, (char*)best + (j + 1) * width) > 0) // 比较大小
			{
				print((char*)best + j * width, (char*)best + (j + 1) * width, width);   // 交换打印
			}
		}
	}
}

void my_int()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), my_cmp_int);     // 对整形数组排序
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void my_struct_age()
{
	XS s[4] = { {"zhansan",30},{"wangwu",20},{"lisi",15},{"huang",55} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), my_cmp_struct_Age);  // 根据结构体中的一个数值对结构体排序；
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d  ", s[i].name, s[i].age);
	}
}

void my_struct_name()
{
	XS s[4] = { {"zhansan",30},{"wangwu",20},{"lisi",15},{"huang",55} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_struct_name);  // 根据结构体中的一个数值对结构体排序；
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d  ", s[i].name, s[i].age);
	}
}
int main()
	{
		// 打印个整形 和 结构体；
		my_int();
		my_struct_age();
		my_struct_name();
		return 0;
	}
