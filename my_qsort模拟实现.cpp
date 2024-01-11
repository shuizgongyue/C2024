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
	return (*(int*)(s1)) - (*(int*)(s2));     // ���εıȽ��㷨
}

int my_cmp_struct_Age( void* a1,  void* a2)
{
	return ((struct XSxx*)a1)->age - ((struct XSxx*)a2)->age; // �Խṹ��Ԫ�صıȽ��㷨
}

int cmp_struct_name( void* e1, void* e2)
{
	//���ֵıȽϾ��ǱȽ��ַ���
	//�ַ����Ƚϲ���ֱ���� > < = ���Ƚϣ� Ӧ��ʹ�ú���strcmp������;
	return strcmp(((struct XSxx*)e1)->name, ((struct XSxx*)e2)->name); // �Խṹ��Ԫ�� ���ֵ�����
}
void print(char* best1,char* best2,int width)   //������ӡ
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
	// ð������ ʵ��
	int i = 0, j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (cmp((char*)best + j * width, (char*)best + (j + 1) * width) > 0) // �Ƚϴ�С
			{
				print((char*)best + j * width, (char*)best + (j + 1) * width, width);   // ������ӡ
			}
		}
	}
}

void my_int()
{
	int arr[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), my_cmp_int);     // ��������������
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void my_struct_age()
{
	XS s[4] = { {"zhansan",30},{"wangwu",20},{"lisi",15},{"huang",55} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), my_cmp_struct_Age);  // ���ݽṹ���е�һ����ֵ�Խṹ������
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d  ", s[i].name, s[i].age);
	}
}

void my_struct_name()
{
	XS s[4] = { {"zhansan",30},{"wangwu",20},{"lisi",15},{"huang",55} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_struct_name);  // ���ݽṹ���е�һ����ֵ�Խṹ������
	for (int i = 0; i < sz; i++)
	{
		printf("%s %d  ", s[i].name, s[i].age);
	}
}
int main()
	{
		// ��ӡ������ �� �ṹ�壻
		my_int();
		my_struct_age();
		my_struct_name();
		return 0;
	}
