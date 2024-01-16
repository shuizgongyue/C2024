#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//��һ���ַ�������

void nx(char* arr)
{
	char* z = arr;
	int len = strlen(arr);
	char* y = arr + len - 1;
	while (z<y)
	{
		char tmp = *z;
		*z = *y;
		*y = tmp;
		z++;
		y--;
	}
}
int main()
{
	char arr[] = "abcdef";
	nx(arr);
	for (int i = 0; i < 6; i++)
	{
		printf("%c ", arr[i]);
	}
	return 0;
}

// ��Sn=a+aa+aaa+aaaaa��ǰ����֮�� a ��һ������

int main()
{
	int a = 0, n = 0;
	scanf("%d%d", &a, &n);
	int sum = 0;
	int str = 0;
	for (int i = 0; i < n; i++)
	{
		str = str * 10 + a;
		sum += str;
	}
	printf("%d", sum);
	return 0;
}

// �� 0-100000 ����������������ӡ��153  1 27 
#include <math.h>

int main()
{
	int i = 0;
	
	for (i = 0; i < 100000; i++)
	{
		// ȷ��λ��
		int w = 0;
		int sum = 0;
		int s = i;
		while (s)
		{
			s /= 10;
			w++;
		}
		s = i;
		while (s)
		{
			int digit = s % 10;
			sum += (int)pow(digit, w);
			s /= 10;
		}
		if (sum == i)
		{
			printf("%d ", sum);
		}
	}
	return 0;
}

// ��ӡһ������

int main()
{
	int a = 0;
	scanf("%d", &a);//7
	if (a != 0)
	{
		// ��ӡ�ϰ벿��
		for (int i = 0; i < a; i++)
		{
			for (int j = 1; j<a-i; j++)
			{
				printf(" ");
			}
			for (int b = 0; b < 2 * i + 1; b++)
			{
				printf("*");
			}
			printf("\n");
		}
		for (int i = 1; i <= a - 1; i++)
		{
			for (int j = 0; j < i; j++)
			{
				printf(" ");
			}
			for (int b = 0; b < 2 * (a - i) - 1; b++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	else
	{
		printf("�������");
	}
	return 0;
}

// һƿ��ˮ 1��Ǯ 2����ƿ���Ի�1ƿ��ˮ����20�� ���Ժȶ���ƿ��

int main()
{
    int qian = 0;
    int kq = 0;
    int sum = 0;
    scanf("%d", &qian);
    if(qian>0)
    {
	sum=2*qian-1;
 }
 
	//������ȵ�
	sum = qian;
	kq = qian;
	//��ƿ�һ�
	while (kq>=2)
	{
		sum += kq / 2;
		kq = kq / 2 + kq % 2;
	}
	printf("%d", sum);
	return 0;
}

// ����һ���������������ݸ�Ϊ������һ�� ż����һ��

void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	//����ʼ��ż��
	while (left<right)
	{
		while (left<right && arr[left] % 2 == 1)//��ֹԽ����ʣ��������������ȫ������ ��ô�ͻ�Խ�����
		{
			left++;
		}
		//���ҿ�ʼ������
		while (left < right && arr[right] % 2 == 0)
		{
			right--;
		}
		if (left != right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 1,3,5,7,9 };

	int sz = sizeof(arr) / sizeof(arr[0]);
	move(arr,sz);
	print(arr,sz);
	//printf("%d", 4 % 2);
	return 0;
}

// ��ӡһ������

int main()
{
	int a = 0;
	scanf("%d", &a);
	if (a != 0)
	{
		// �ϰ벿��
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < (a - 1)-i; j++)//�п�����
			{
				printf(" ");
			}
			for (int b = 0; b <(2*i)+1; b++)
			{
				printf("*");
			}
			printf("\n");
		}
		// �²���
		for (int i = 1; i < a; i++)
		{
			for (int j = 0; j < i; j++)//�п�����
			{
				printf(" ");
			}
			for (int b = 0; b < 2 * (a - i) - 1; b++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	else
	{
		printf("�������");
	}
	return 0;
}

// qsort ģ��ʵ��

typedef struct xx
{
	char name[50];
	int id;
}xx;

int my_tmp_name(void* e1, void* e2)
{
	return strcmp(((struct xx*)e1)->name, ((struct xx*)e2)->name);
}

int my_tmp_int(void* e1, void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void print(char* arr, char* arr1, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *arr;
		*arr = *arr1;
		*arr1 = tmp;
		arr++;
		arr1++;
	}
}

void my_qsort(void* arr, int sz, int width, int (*cmp)(void* s1, void* s2))
{
	int i, j;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			// �Ƚϴ�С
			if (cmp((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0)
			{
				// ����
				print((char*)arr + j * width, (char*)arr + (j + 1) * width, width);
			}
		}
	}
}
int main()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), my_tmp_int);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	xx s[] = { {"zhansan",40},{"wangwu",30},{"lisi",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), my_tmp_name);
	for (int i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}
	return 0;
}

// ������ת k ���ַ���
#include <assert.h>

void xz(char* arr, int sz,int b)
{
	assert(arr);  ���� �ж��ַ�����Ч�� 
	int i = 0;
	for (int i = 0; i < b; i++) // ��ת b ��
	{
		// ��һ���ַ��ȴ�����
		char tmp = *arr;
		// �ӵڶ����ַ���ʼ����
		for (int j = 0; j < sz - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		// �ѵ�һ���ַ���������λ����
		*(arr + sz - 1) = tmp;
	}
}
int main()
{
	char arr[] = "abcdef";
	int sz = strlen(arr);
	xz(arr, sz,2);
	printf("%s\n", arr);
	return 0;
 } �ڶ����㷨 

// abcdef
// ba fedc
// cdefba
void nx(char* left,char* right)
{
	assert(left != NULL && right != NULL);
	while ( left < right ) 
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void xz(char* arr, int a)
{
	assert(arr);
	int len = strlen(arr);
	assert(a < len);
	nx(arr,arr+a-1);//�����һ��
	nx(arr+a,arr+len-1);//����ڶ���
	nx(arr,arr+len-1);//���������
}
int main()
{
	char arr[] = "abcdef";
	xz(arr,3);
	printf("%s", arr);
	return 0;
}

// дһ�������ж��ж� arr1 �ǲ����� arr��ת����

int pd(char* arr, char* arr1)
{
	int len = strlen(arr);
	int len1 = strlen(arr1);
	if (len != len1)
		return 0;
	for (int i = 0; i < len; i++)
	{
		xz(arr, 1);
		int str = strcmp(arr, arr1);
		if (str == 0)
			return 1;
	}
	return 0;
}
int main()
{
	char arr[] = "abcdefl";
	char arr1[] = "dcefab";
	int ret = pd(arr, arr1);
	if (ret != 0)
		printf("Yes");
	else
		printf("No");
	return 0;
}

// ������д��
#include <assert.h>
int pd(char* str, char* str1)
{
	assert(str != NULL && str1 != NULL); �ж��ǲ��ǿ��ַ�
	int len = strlen(str);
	int len1 = strlen(str1);			 
	if (len != len1)					 �ж������ַ��ǲ��ǲ���� �������ôһ�������ִ�
		return 0;
	strncat(str, str, len);				 �� str ����׷�� len �� str�ַ�
	char* a = strstr(str, str1);		 �ж� str1 �ǲ��� str ���ִ� �Ǿͷ���ָ�� str1 ��Ԫ�ص�ָ��
	if (a != NULL)
		return 1;
	else
		return 0;
}
int main()
{
	char str[50] = "abcdef";
	char str1[] = "defabc";
	int b = pd(str, str1);
	if (b != 0)
		printf("Yes");
	else
		printf("No");
	return 0;
}*/

// ���Ͼ���
// ��һ�����־��󣬾����ÿ�д������ǵ��������ϵ����ǵ����ģ�
// дһ�������������ľ����� ����ĳ�������Ƿ���ڣ����ڷ����±�
// ʱ�临�Ӷ�С�� 0(N)��
// 1 2 3
// 4 5 6
// 7 8 9 
// �ؼ����������Ͻǵ�Ԫ��
int cz(int arr[3][3], int a, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while ( x <= *px - 1 && y >= 0 )
	{
		if (arr[x][y] > a)
		{
			y--;
		}
		else if (arr[x][y] < a)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int a = 0;
	scanf("%d", &a);
	int len = sizeof(arr) / sizeof(arr[0]);
	int x = 3;
	int y = 3;
	int c = cz(arr, a , &x, &y);
	if (c == 1)
		printf("�ҵ����±�Ϊ��%d %d", x, y);
	else
		printf("NO");
	return 0;
}