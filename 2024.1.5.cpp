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
//	int len = sizeof(arr)/sizeof(arr[0]); // ����
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
		// ������� ����Ƿ������� �еĻ����׳�����
		assert(arr1 != NULL); // ��� ���ε�ʱ�򴫵� ��ֵ��ô�ͻᱨ��;
		assert(arr != NULL);
		while (*arr1++ = *arr++)
		{

		}
	}
// 5
	void my_strcpy(char* arr1, const char* arr) // ʹ�� const ʹ��ӵ�г����� �Ӷ����ܱ��ı�
	{
		// ������� ����Ƿ������� �еĻ����׳�����
		assert(arr1 != NULL); // ��� ���ε�ʱ�򴫵� ��ֵ��ô�ͻᱨ��; 
		assert(arr != NULL);
		//while (*arr++ = *arr1++) ��д���ᱨ��
		while (*arr1++ = *arr++)
		{

		}
	}

	// const char* arr ��ʾ *arr���ܱ��޸�  ��
	// char* const arr ��ʾ arr���ܱ��޸�  �� �����÷��и���������
			//int main()
			//{
			//	char arr[] = "ssbnfjasbf";
			//	char arr1[15] = "0";
			//	// strcpy(arr1, arr);  ���庯��ʵ�ָù��ܣ�
			//	//printf("%c", arr1[4]);
			//	my_strcpy(arr1, arr);
			//	//my_strcpy(arr1, NULL);
	
			//	return 0;
			//}

// ���ð������;
void mp(int* arr,int len)
{
	//��һ�ζԱȺ���Ҫ���� len - 1 ��
	for (int i = 0; i < len - 1; i++)
	{
		//��һ�ζԱ���� һ��Ԫ���Ѿ����ŵ���ȷ��λ�� �����ܹ��� 10 ��Ԫ�� ��һ�κ� ��ʣ 8��Ԫ����Ҫ�Ա�
		for (int j = 0; j < len - 1 - i ; j++)
		{
			if (arr[j] > arr[j + 1]) // ǰ����Ԫ�ضԱ�
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
//	int arr[] = {10,9,8,7,6,5,4,3,2,1,0 }; //ʹ������
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
	// �����±�
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

// ======  дһ������ʵ�ֶ��ֲ���  �����ҵ��˸����� ��ô������������±�;
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int a = 0;
	scanf("%d", &a);	// ���ܲ��ҵ�ֵ;
	int len = sizeof(arr) / sizeof(arr[0]);
	int jg=my_tu(arr,len,a);
	if (jg != -1)
		printf("�ҵ����±�Ϊ��%d ", jg);
	else
		printf("û���ҵ�");
	return 0;
}