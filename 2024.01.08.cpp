#include <stdio.h>

// ����ָ��  ָ������

// int arr[10] = { 0 };
// arr -- ��Ԫ�صĵ�ַ
// &arr[0] -- ��Ԫ�صĵ�ַ
// &arr -- ����ĵ�ַ
		/*int mian()
		{
			//����ָ��
			int arr[] = { 1,2,3,4 };
			int(*p)[4] = &arr;
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", (*p)[i]);

			}
			 ����ָ�룺��һ��ָ�� �������������ĵ�ַ
			return 0;
		}*/


		/*int main()
		{
	
			//ָ������  ��һ������ ������ŵ�ַ��һ���������͵�ָ��
			int a = 10;
			int b = 20;
			int c = 30;
			int* arr[] = { &a,&b,&c }; ��һ������ ������ŵ�ַ��һ���������͵�ָ��
			for (int i = 0; i < 3; i++)
			{
				printf("%d ", *(arr[i]));
			}
			return 0;
		}*/

// &arr vs arr ������
// &arr ��ʾ������������ĵ�ַ
// arr  ���󲿷ֱ�ʾ����������׵�ַ

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

	int arr[5];				��һ�����ε����� ���������Ԫ��
	int *parr1[10];			��һ������ ������ ʮ�� Ԫ�� Ԫ�ص������� int *     -- ָ������
	int (*parr2)[10];		��һ�� ָ�� ������ ʮ�� ���ε�Ԫ��;  -- ����ָ��
	int (*parr3[10])[5];	��һ������ ������ ʮ�� Ԫ�� ÿ��Ԫ����һ��  ָ��
							ÿ�� ָ�� ָ����������������Ԫ��
*/

void print(int arr[3][5], int x, int y)
{
	// ������ʽ
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
	// ָ����ʽ
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			//printf("%d ", *(*(p+i)+j));  //�Ȱѵ�һ�еĵ�ַ������ ���ҵ���Ӧ��Ԫ��
			// ������ʽ�����Ż�Ϊ�������ʽ
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
		/* int main()
		{
			int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
			//print(arr, 3, 5);
			print2(arr, 3, 5);  // ��ά���鴫�ε��׵�ַ �ǵ�һ�е�Ԫ�� ��ַ
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

// һά���鴫�� 
/*	void test(int arr[]) //Y
	{}
	void test(int arr[10]) //Y
	{}
	void test(int *arr)	   //Y
	{}
	void test2(int *arr[20]) // Y  
	{}
	void test(int **arr)     // Y arr2��һ��ָ���ַ�ö���ָ�����û����
	{}
*/

		/*int main()
		{
			int arr[10] = { 0 };
			int* arr2[20] = { 0 }; //����ָ��  ������20�����ε�ָ��Ԫ��
			test(arr);
			test2(arr2);
			return 0;
		}*/

// ��ά���鴫��

/*	void tat(int* arr)		// N  ������һ��������� �������һ������ָ�����
	{}
	void tat(int* arr[5])   // N   �������һ��ָ������ ������5�� int * ���͵�Ԫ�� ����
	{}
	void tat(int (*att)[5])	// Y   ������һ��ָ�� ������������ε�Ԫ�� ��ȷ
	{}
	void tat(int **arr)     // N   ������һ������ָ��Ӧ�ý��ܵ���һ��һ��ָ������ĵ�ַ ���ܵ���һ������ĵ�ַ ����
	{}
*/
		/*int main()
		{
			int arr[3][5] = { 0 };
			tat(arr); // ��ά���鴫�� �Ǵ�����������ĵ�һ��
			return 0;
		}*/

// ����ָ��  -- ��һ��ָ������ ָ��һ������;
// �����ķ������� + ָ���� + ������������  

int Add(int a, int b)
{
	return printf("%d", a + b);
}
int main()
{
	int a = 10;
	int b = 20;
	//int (*p)(int, int) = Add;  //�������Ǻ����ĵ�ַ
	int (*p)(int, int) = &Add;   
	p(a, b);
	return 0;
}