#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (* (void (*)() ) 0 )(); 把 0 强制类型转为 void （*）（）函数指针类型 0就是一个函数指针的地址
						// 最后调用 0 地址处的函数

// void (*signal(int, void(*)(int)))(int);  
// signal 是一个函数声明 参数有两个一个是 int 一个是函数指针，这个指针参数是 int 类型 返回是 void类型；
// signal 函数的返回类型是一个函数指针 这个指针参数是 int 类型 返回是 void类型;


// 函数指针数组   -- 是一个数组 里面 里面存放了指向函数的指针       有称转移表
int sum(int x, int y)
{
	return x + y;
}
int sum1(int x, int y)
{
	return x - y;
}
int sum2(int x, int y)
{
	return x * y;
}
int sum3(int x, int y)
{
	if (y != 0)
		return x / y;
	else
	{
		printf("除数不能为0");
		return 0;
	}
}
/*	int main()
	{
		int(*arr[4])(int, int) = { sum,sum1,sum2,sum3 }; // 函数指针数组
		 arr 是一个数组 里面有4个元素 元素的类型是 指针函数 返回类型是 int ;
		return 0;
	}*/

/*	char* my_strcpy(char* dest, const char* src);

	 写一个指针 pf 能后指向 my_strcpy;
	
	char* (*pf)(char* dest, const char* src) = my_strcpy;
	
	写一个函数指针数组 pfarr 能够存放四个 my_strcpy 函数地址;
	
	char* (*pfarr[4])(char* dest, const char* src) = { my_strcpy };
*/
void CD()
{
	printf("********************\n");
	printf("**  1:加   2:减   **\n");
	printf("**  3:乘   4:除   **\n");
	printf("****   0：erc  *****\n");
	printf("********************\n");
}
/*		int main()
		{
			int input = 0;
			int(*arr[])(int, int) = { 0,sum,sum1,sum2,sum3 };
			do
			{
				int x = 0, y = 0;
				CD();
				printf("请选择功能\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					printf("请输入参数\n");                     每个选择都会出现 会出现涌余 要优化
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 2:
					printf("请输入参数\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 3:
					printf("请输入参数\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 4:
					printf("请输入参数\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 0:
					printf("你以退出计算器\n");
					break;
				default:
					printf("选择错误\n");
					break;
				}
			} while (input);
			return 0;
		}*/

// 优化后    回调函数 -- 回调函数就是一个通过函数指针调用的函数。
// 如果你把函数的指针（地址）作为参数传递给另一个
// 函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数
// 的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进
// 行响应。
 void cool (int (*pf)(int,int))          // 回调函数
{
	int x = 0, y = 0;
	printf("请输入参数\n");
	scanf("%d %d", &x, &y);
	printf("%d\n", pf(x, y));
	
}
/*		int main()
		{
			int input = 0;
			//int(*arr[])(int, int) = { 0,sum,sum1,sum2,sum3 };
			do
			{
		
				CD();
				printf("请选择功能\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					cool(sum);                //通过函数的形式 根据选择 传不同的函数 实现功能
					break;
				case 2:
					cool(sum1);
					break;
				case 3:
					cool(sum2);
					break;
				case 4:
					cool(sum3);
					break;
				case 0:
					printf("你以退出计算器\n");
					break;
				default:
					printf("选择错误\n");
					break;
				}
			} while (input);
			return 0;
		} 
*/

 // qsort 快速排序(可以排序任何类型的数据)   
 //			里面有四个参数（1：排序的数组首元素地址 2：排序数组元素的个数 3：变量参数的大小  单位字节
 //			4：排序的函数  函数用来比较两个元素的函数，，需自己实现。这个函数不返回任何值
 //			但回直接修改传入的排序变量；
 //			排序函数的格式必须为： int (变量名)参数(const void* e1, const void* e2)
 //         这个比较函数的特点：当第一个元素 < 第二个元素 返回 <0， 
 //								当第一个元素 = 第二个元素 返回 0,
 //								当第一个元素 > 第二个元素 返回 >0

 int cmp_int(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));     // 整形的比较算法
 }
 void tst_int()
 {
	 int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	 int sz = sizeof(arr) / sizeof(arr[0]);
	 qsort(arr, sz, sizeof(arr[0]), cmp_int);  // 对整形的排序
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%d ", arr[i]);
	 }
 }

 int cmp_float(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));    // 浮点形的比较算法
 }
 void tst_float()
 {
	 float arr1[] = { 5.0,4.0,3.0,2.0,1.0,0.0 };
	 int sz = sizeof(arr1) / sizeof(arr1[0]);
	 qsort(arr1, sz, sizeof(arr1[0]), cmp_float);  // 对浮点数的排序
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%f ", arr1[i]);
	 }
 }

 typedef struct ryxx
 {
	 char name[20];
	 int age;
 }xx;
 int cmp_struct_age(const void* e1, const void* e2)
 {
	 return ((struct ryxx*)e1)->age - ((struct ryxx*)e2)->age; // 对结构体元素的比较算法
 }
 void tst_struct_age()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // 对结构体的比较;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_age);					// 比较结构体的中一个参数排序;
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%s %d  ", s[i].name, s[i].age);
	 }
 }
 int cmp_struct_name(const void* e1, const void* e2)
 {
	 //名字的比较就是比较字符串
	 //字符串比较不能直接用 > < = 来比较； 应该使用函数strcmp来进行;
	 return strcmp(((struct ryxx*)e1)->name, ((struct ryxx*)e2)->name); // 对结构体元素 名字的排序
 }
 void tst_struct_name()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // 对结构体的比较;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_name);					// 比较结构体的中一个参数排序;
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%s %d  ", s[i].name, s[i].age);
	 }
 }
 int main()
 {
	tst_int();
	printf("\n");
	tst_float();
	printf("\n");
	tst_struct_age();
	printf("\n");
	tst_struct_name();
	return 0;
 }
