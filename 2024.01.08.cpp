#include <stdio.h>

// 数组指针  指针数组

// int arr[10] = { 0 };
// arr -- 首元素的地址
// &arr[0] -- 首元素的地址
// &arr -- 数组的地址
		/*int mian()
		{
			//数组指针
			int arr[] = { 1,2,3,4 };
			int(*p)[4] = &arr;
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", (*p)[i]);

			}
			 数组指针：是一个指针 是用来存放数组的地址
			return 0;
		}*/


		/*int main()
		{
	
			//指针数组  是一个数组 用来存放地址的一个数组类型的指针
			int a = 10;
			int b = 20;
			int c = 30;
			int* arr[] = { &a,&b,&c }; 是一个数组 用来存放地址的一个数组类型的指针
			for (int i = 0; i < 3; i++)
			{
				printf("%d ", *(arr[i]));
			}
			return 0;
		}*/

// &arr vs arr 的区别
// &arr 表示的是整个数组的地址
// arr  绝大部分表示的是数组的首地址

		/*int main()
		{
			int arr[10] = { 0 };
			printf("%p\n", arr);
			printf("%p\n", &arr);

			printf("arr+1= %p\n", arr+1);
			printf("&arr+1= %p\n", &arr+1);
			return 0;
		}*/


/*

	int arr[5];				是一个整形的数组 里面有五个元素
	int *parr1[10];			是一个数组 里面有 十个 元素 元素的类型是 int *     -- 指针数组
	int (*parr2)[10];		是一个 指针 里面有 十个 整形的元素;  -- 数组指针
	int (*parr3[10])[5];	是一个数组 里面有 十个 元素 每个元素是一个  指针
							每个 指针 指向的数组有五个整形元素
*/

void print(int arr[3][5], int x, int y)
{
	// 数组形式
	int i, j;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print2(int(*p)[5], int x, int y)
{
	// 指针形式
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			//printf("%d ", *(*(p+i)+j));  //先把第一行的地址解引用 在找到对应的元素
			// 以上形式可以优化为下面的形式
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
		/* int main()
		{
			int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
			//print(arr, 3, 5);
			print2(arr, 3, 5);  // 二维数组传参的首地址 是第一行的元素 地址
			return 0;
		}  

/*int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", p[i]);
		printf("%d ", *(p + i));
		printf("%d ", *(arr+i));
		printf("%d ", arr[i]);
		
	}
	return 0;
}*/

// 一维数组传参 
/*	void test(int arr[]) //Y
	{}
	void test(int arr[10]) //Y
	{}
	void test(int *arr)	   //Y
	{}
	void test2(int *arr[20]) // Y  
	{}
	void test(int **arr)     // Y arr2是一个指针地址用二级指针接收没问题
	{}
*/

		/*int main()
		{
			int arr[10] = { 0 };
			int* arr2[20] = { 0 }; //数组指针  里面有20个整形的指针元素
			test(arr);
			test2(arr2);
			return 0;
		}*/

// 二维数组传参

/*	void tat(int* arr)		// N  传参是一个数组或者 这里给了一个整形指针错误
	{}
	void tat(int* arr[5])   // N   这里的是一个指针数组 里面有5个 int * 类型的元素 错误
	{}
	void tat(int (*att)[5])	// Y   这里是一个指针 里面有五个整形的元素 正确
	{}
	void tat(int **arr)     // N   这里是一个二级指针应该接受的是一个一级指针变量的地址 接受的是一个数组的地址 错误
	{}
*/
		/*int main()
		{
			int arr[3][5] = { 0 };
			tat(arr); // 二维数组传参 是传的数组里面的第一行
			return 0;
		}*/

// 函数指针  -- 是一个指针用于 指向一个函数;
// 函数的返回类型 + 指针名 + 函数参数类型  

int Add(int a, int b)
{
	return printf("%d", a + b);
}
int main()
{
	int a = 10;
	int b = 20;
	//int (*p)(int, int) = Add;  //函数名是函数的地址
	int (*p)(int, int) = &Add;   
	p(a, b);
	return 0;
}

 (* (void (*)() ) 0 )(); 把 0 强制类型转为 void （*）（）函数指针类型 0就是一个函数指针的地址
						// 最后调用 0 地址处的函数

 void (*signal(int, void(*)(int)))(int);  
 signal 是一个函数声明 参数有两个一个是 int 一个是函数指针，这个指针参数是 int 类型 返回是 void类型；
 signal 函数的返回类型是一个函数指针 这个指针参数是 int 类型 返回是 void类型;
