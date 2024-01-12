#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/*
	int main()
	{
		//一维数组
		int a[] = { 1,2,3,4 };
		printf("%d\n", sizeof(a));		// 16  计算数组总大小
		printf("%d\n", sizeof(a + 0));	// 4/8  这里表示首元素地址 +0 还是地址 地址就是4/8字节
		printf("%d\n", sizeof(*a));		// 4	这里表示首元素地址，解引用后就是首元素
		printf("%d\n", sizeof(a + 1));	// 4/8	这里表示首元素地址 +1 还是地址 地址就是4/8字节
		printf("%d\n", sizeof(a[1]));	// 4	表示第二个元素大小
		printf("%d\n", sizeof(&a));		// 4/8	取出的是数组地址 地址的大小就是 4/8字节
		printf("%d\n", sizeof(*&a));	// 16	取出a的地址解引用后访问 数组 求整个数组大小
		printf("%d\n", sizeof(&a + 1));	// 4/8	出的数组地址 +1 跳过一个地址 地址的大小就是 4/8字节
		printf("%d\n", sizeof(&a[0]));	// 4/8	取第一个元素地址 地址的大小就是 4/8字节
		printf("%d\n", sizeof(&a[0] + 1));// 4/8	取第二个元素地址 地址的大小就是 4/8字节
		//字符数组
		char arr[] = { 'a','b','c','d','e','f' };
		printf("%d\n", sizeof(arr));			// 6	计算数组大小  
		printf("%d\n", sizeof(arr + 0));		// 4/8	arr首元素地址+0 还是首元素地址 
		printf("%d\n", sizeof(*arr));			// 1	arr首元素地址解引用后 就是a 一个字节
		printf("%d\n", sizeof(arr[1]));			// 1		
		printf("%d\n", sizeof(&arr));			// 4/8	取arr地址 地址大小4/8字节
		printf("%d\n", sizeof(&arr + 1));		// 4/8	&arr + 1 跳过arr地址 后还是地址地址大小4/8字节
		printf("%d\n", sizeof(&arr[0] + 1));	// X	取第二个元素地址 地址地址大小4/8字节
	
		printf("%d\n", strlen(arr));			// sj
		printf("%d\n", strlen(arr + 0));		// sj
		//printf("%d\n", strlen(*arr));			// 首地址解引用后传 a ASCII值97 非法访问
		//printf("%d\n", strlen(arr[1]));		   传参 b ASCII值 98 非法访问内存
		printf("%d\n", strlen(&arr));			// sj
		printf("%d\n", strlen(&arr + 1));		// sj 比上个小6
		printf("%d\n", strlen(&arr[0] + 1));	// sj 比上个小1

		char arr[] = "abcdef";
		printf("%d\n", sizeof(arr));			// 算上 \0 7个字节
		printf("%d\n", sizeof(arr + 0));		// 4/8 首地址 + 0还是地址
		printf("%d\n", sizeof(*arr));			// 1 首地址解引用后 就是首元素 1字节
		printf("%d\n", sizeof(arr[1]));			// 1 计算首元素大小
		printf("%d\n", sizeof(&arr));			// 4/8  地址大小
		printf("%d\n", sizeof(&arr + 1));		// 4/8  首地址 + 1跳过的还是地址 大小 4/8
		printf("%d\n", sizeof(&arr[0] + 1));	// 4/8第二个元素的地址 地址大小 4/8字节
		//	char arr[] = "abcdef\0";
		printf("%d\n", strlen(arr));			// 6
		printf("%d\n", strlen(arr + 0));		// 6
		printf("%d\n", strlen(*arr));			// 首地址解引用后传 a ASCII值97 非法访问    错误
		printf("%d\n", strlen(arr[1]));			// 传参 b ASCII值 98 非法访问内存  非法访问 错误
		printf("%d\n", strlen(&arr));			// 6  &arr代表整个地址
		printf("%d\n", strlen(&arr + 1));		// sj 跳过 arr 地址 随机大小
		printf("%d\n", strlen(&arr[0] + 1));	// 5 第二个元素开始计算             
		char* p = "abcdef"; 指针存放首地址
		printf("%d\n", sizeof(p));				// 4/8 计算指针变量 p 的大小
		printf("%d\n", sizeof(p + 1));			// 4/8 p + 1 得到字符 吧地址 4/8字节
		printf("%d\n", sizeof(*p));				// 1 首地址解应用后得到 a 1字节
		printf("%d\n", sizeof(p[0]));			// 1 和上一句等价
		printf("%d\n", sizeof(&p));				// 4/8 计算 P 的地址 
		printf("%d\n", sizeof(&p + 1));			// 4/8 还是地址
		printf("%d\n", sizeof(&p[0] + 1));		// 4/8 取第二个元素 b 的地址
		char* p = "abcdef"; 指针存放首地址
		printf("%d\n", strlen(p));		// 6
		printf("%d\n", strlen(p+1));	// 5
		printf("%d\n", strlen(*p));		// 
		printf("%d\n", strlen(p[0]));	//
		printf("%d\n", strlen(&p));		// sj
		printf("%d\n", strlen(&p+1));	// sj
		printf("%d\n", strlen(&p[0]+1));// 5 元素b地址往后计算

		//二维数组
		int a[3][4] = {0}; 里面有12个以元素
		printf("%d\n",sizeof(a));			// 12*4=48;
		printf("%d\n",sizeof(a[0][0]));		// 4 计算第一个元素
		printf("%d\n",sizeof(a[0]));		// 16 计算第一行元素
		printf("%d\n",sizeof(a[0]+1));		// 4/8 没有单独存在 表示首元素地址+1 表示第二个元素地址
		printf("%d\n",sizeof(*(a[0]+1)));	// 4 计算第一行第二个元素大小
		printf("%d\n",sizeof(a+1));			// 4/8 首元素 +1代表第二行元素地址
		printf("%d\n",sizeof(*(a+1)));		// 16 计算第二行大小
		printf("%d\n",sizeof(&a[0]+1));		// 4/8 第二行的地址
		printf("%d\n",sizeof(*(&a[0]+1)));	// 16 计算第二行元素大小
		printf("%d\n",sizeof(*a));			// 16 计算第一行大小
		printf("%d\n",sizeof(a[3]));		// 16 该函数不会去访问数组，这一行存不存在不重要
											   只需要计算这一行的大小 一行四个元素 16字节
		return 0;
		1. sizeof(数组名)，这里的数组名表示整个数组，计算的是整个数组的大小。
		2. &数组名，这里的数组名表示整个数组，取出的是整个数组的地址。
		3. 除此之外所有的数组名都表示首元素的地址。

	}
*/
/*	int main()
	{
		int a[5] = { 1, 2, 3, 4, 5 };
		int *ptr = (int *)(&a + 1);
		printf( "%d,%d", *(a + 1), *(ptr - 1));
		*(a + 1)= a 代表首元素地址 +1 等于第二个元素地址 解引用后 为第二个元素 2
		*(ptr -1) = (&a + 1)等于跳到a后面的地址强制类型转换成 int * 指针类型存放到 ptr里面
		ptr - 1 等于地址往后退一个 相当于访问 a 最后一个元素
		return 0;
	}
*/
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
/*
int main()
{
	printf("%p\n", p + 0x1);//0x1=1 这里指加一个结构体的大小 20字节  0x100000 + 20=0x100014
	printf("%p\n", (unsigned long)p + 0x1); // 这里把 p 转换成无符号长整形 =  0x100000 + 1 =0x100001
	printf("%p\n", (unsigned int*)p + 0x1); // 这里把 p 转换成无符号整形指针
											// + 1 等于加一个指针大小 4 字节 =  0x100000 + 4 = 0x100004
	return 0;
}*/
/*
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	ptr1等于指向数组 a 的后面的空间 -1 后等于 4
	ptr2等于指向首地址向后一个元素 2 强制转换成 int *类型
	4  2
	return 0;
}*/
/*
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	{ (0, 1), (2, 3), (4, 5) } 是逗号表达式 只初始化了 1 3 5 其余补 0
	表达形式为：{{1,3},{5,0},{0,0}};
	int* p;
	p = a[0]; 表达第一行首元素地址;
	printf("%d", p[0]); p[0]=*(p+0)表达第一行首元素地址
	return 0;
}*/
/*
int main()
{									     p2	   a2
	int a[5][5];     00000 00000 00000 00000 00000
	int(*p)[4];		 p   p1   p2   p3	p4		    a[4][2]
	p =  a; 首地址p指向的是四个元素 每加一i就跳过四个元素  p[4][2]=*(*(p+4)+2) 
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); 
			&p[4][2] - &a[4][2] 中间相差四个元素 = -4
			%p打印的时候就是打印无符号数 -4存到内存的是补码 就直接打印
	return 0;
}*/
/*
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1); 指向整个数组地址后的一个位置
	int* ptr2 = (int*)(*(aa + 1)); aa首地址 +1 等于指向第二行第一个元素
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));  10 5
	return 0;
}
*/
/*
int main()
{
	char* a[] = { "work","at","alibaba" }; 这是数组指针 里面存放了三个地址 
	char** pa = a; 二级指针存放了 数组a 第一个指针的地址
	pa++;			跳过一个 char * 的位置 来到 第二个元素首地址
	printf("%s\n", *pa); at
	return 0;
}
*/
/*
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c }; 
	char*** cpp = cp;
	printf("%s\n", **++cpp); //POINT
	printf("%s\n", *-- * ++cpp + 3);// ER
	printf("%s\n", *cpp[-2] + 3);//ST
	printf("%s\n", cpp[-1][-1] + 1);//EW
	return 0;
}
*/
