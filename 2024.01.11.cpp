#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

/*
	int main()
	{
		//һά����
		int a[] = { 1,2,3,4 };
		printf("%d\n", sizeof(a));		// 16  ���������ܴ�С
		printf("%d\n", sizeof(a + 0));	// 4/8  �����ʾ��Ԫ�ص�ַ +0 ���ǵ�ַ ��ַ����4/8�ֽ�
		printf("%d\n", sizeof(*a));		// 4	�����ʾ��Ԫ�ص�ַ�������ú������Ԫ��
		printf("%d\n", sizeof(a + 1));	// 4/8	�����ʾ��Ԫ�ص�ַ +1 ���ǵ�ַ ��ַ����4/8�ֽ�
		printf("%d\n", sizeof(a[1]));	// 4	��ʾ�ڶ���Ԫ�ش�С
		printf("%d\n", sizeof(&a));		// 4/8	ȡ�����������ַ ��ַ�Ĵ�С���� 4/8�ֽ�
		printf("%d\n", sizeof(*&a));	// 16	ȡ��a�ĵ�ַ�����ú���� ���� �����������С
		printf("%d\n", sizeof(&a + 1));	// 4/8	���������ַ +1 ����һ����ַ ��ַ�Ĵ�С���� 4/8�ֽ�
		printf("%d\n", sizeof(&a[0]));	// 4/8	ȡ��һ��Ԫ�ص�ַ ��ַ�Ĵ�С���� 4/8�ֽ�
		printf("%d\n", sizeof(&a[0] + 1));// 4/8	ȡ�ڶ���Ԫ�ص�ַ ��ַ�Ĵ�С���� 4/8�ֽ�
		//�ַ�����
		char arr[] = { 'a','b','c','d','e','f' };
		printf("%d\n", sizeof(arr));			// 6	���������С  
		printf("%d\n", sizeof(arr + 0));		// 4/8	arr��Ԫ�ص�ַ+0 ������Ԫ�ص�ַ 
		printf("%d\n", sizeof(*arr));			// 1	arr��Ԫ�ص�ַ�����ú� ����a һ���ֽ�
		printf("%d\n", sizeof(arr[1]));			// 1		
		printf("%d\n", sizeof(&arr));			// 4/8	ȡarr��ַ ��ַ��С4/8�ֽ�
		printf("%d\n", sizeof(&arr + 1));		// 4/8	&arr + 1 ����arr��ַ ���ǵ�ַ��ַ��С4/8�ֽ�
		printf("%d\n", sizeof(&arr[0] + 1));	// X	ȡ�ڶ���Ԫ�ص�ַ ��ַ��ַ��С4/8�ֽ�
	
		printf("%d\n", strlen(arr));			// sj
		printf("%d\n", strlen(arr + 0));		// sj
		//printf("%d\n", strlen(*arr));			// �׵�ַ�����ú� a ASCIIֵ97 �Ƿ�����
		//printf("%d\n", strlen(arr[1]));		   ���� b ASCIIֵ 98 �Ƿ������ڴ�
		printf("%d\n", strlen(&arr));			// sj
		printf("%d\n", strlen(&arr + 1));		// sj ���ϸ�С6
		printf("%d\n", strlen(&arr[0] + 1));	// sj ���ϸ�С1

		char arr[] = "abcdef";
		printf("%d\n", sizeof(arr));			// ���� \0 7���ֽ�
		printf("%d\n", sizeof(arr + 0));		// 4/8 �׵�ַ + 0���ǵ�ַ
		printf("%d\n", sizeof(*arr));			// 1 �׵�ַ�����ú� ������Ԫ�� 1�ֽ�
		printf("%d\n", sizeof(arr[1]));			// 1 ������Ԫ�ش�С
		printf("%d\n", sizeof(&arr));			// 4/8  ��ַ��С
		printf("%d\n", sizeof(&arr + 1));		// 4/8  �׵�ַ + 1�����Ļ��ǵ�ַ ��С 4/8
		printf("%d\n", sizeof(&arr[0] + 1));	// 4/8�ڶ���Ԫ�صĵ�ַ ��ַ��С 4/8�ֽ�
		//	char arr[] = "abcdef\0";
		printf("%d\n", strlen(arr));			// 6
		printf("%d\n", strlen(arr + 0));		// 6
		printf("%d\n", strlen(*arr));			// �׵�ַ�����ú� a ASCIIֵ97 �Ƿ�����    ����
		printf("%d\n", strlen(arr[1]));			// ���� b ASCIIֵ 98 �Ƿ������ڴ�  �Ƿ����� ����
		printf("%d\n", strlen(&arr));			// 6  &arr����������ַ
		printf("%d\n", strlen(&arr + 1));		// sj ���� arr ��ַ �����С
		printf("%d\n", strlen(&arr[0] + 1));	// 5 �ڶ���Ԫ�ؿ�ʼ����             
		char* p = "abcdef"; ָ�����׵�ַ
		printf("%d\n", sizeof(p));				// 4/8 ����ָ����� p �Ĵ�С
		printf("%d\n", sizeof(p + 1));			// 4/8 p + 1 �õ��ַ� �ɵ�ַ 4/8�ֽ�
		printf("%d\n", sizeof(*p));				// 1 �׵�ַ��Ӧ�ú�õ� a 1�ֽ�
		printf("%d\n", sizeof(p[0]));			// 1 ����һ��ȼ�
		printf("%d\n", sizeof(&p));				// 4/8 ���� P �ĵ�ַ 
		printf("%d\n", sizeof(&p + 1));			// 4/8 ���ǵ�ַ
		printf("%d\n", sizeof(&p[0] + 1));		// 4/8 ȡ�ڶ���Ԫ�� b �ĵ�ַ
		char* p = "abcdef"; ָ�����׵�ַ
		printf("%d\n", strlen(p));		// 6
		printf("%d\n", strlen(p+1));	// 5
		printf("%d\n", strlen(*p));		// 
		printf("%d\n", strlen(p[0]));	//
		printf("%d\n", strlen(&p));		// sj
		printf("%d\n", strlen(&p+1));	// sj
		printf("%d\n", strlen(&p[0]+1));// 5 Ԫ��b��ַ�������

		//��ά����
		int a[3][4] = {0}; ������12����Ԫ��
		printf("%d\n",sizeof(a));			// 12*4=48;
		printf("%d\n",sizeof(a[0][0]));		// 4 �����һ��Ԫ��
		printf("%d\n",sizeof(a[0]));		// 16 �����һ��Ԫ��
		printf("%d\n",sizeof(a[0]+1));		// 4/8 û�е������� ��ʾ��Ԫ�ص�ַ+1 ��ʾ�ڶ���Ԫ�ص�ַ
		printf("%d\n",sizeof(*(a[0]+1)));	// 4 �����һ�еڶ���Ԫ�ش�С
		printf("%d\n",sizeof(a+1));			// 4/8 ��Ԫ�� +1����ڶ���Ԫ�ص�ַ
		printf("%d\n",sizeof(*(a+1)));		// 16 ����ڶ��д�С
		printf("%d\n",sizeof(&a[0]+1));		// 4/8 �ڶ��еĵ�ַ
		printf("%d\n",sizeof(*(&a[0]+1)));	// 16 ����ڶ���Ԫ�ش�С
		printf("%d\n",sizeof(*a));			// 16 �����һ�д�С
		printf("%d\n",sizeof(a[3]));		// 16 �ú�������ȥ�������飬��һ�д治���ڲ���Ҫ
											   ֻ��Ҫ������һ�еĴ�С һ���ĸ�Ԫ�� 16�ֽ�
		return 0;
		1. sizeof(������)���������������ʾ�������飬���������������Ĵ�С��
		2. &���������������������ʾ�������飬ȡ��������������ĵ�ַ��
		3. ����֮�����е�����������ʾ��Ԫ�صĵ�ַ��

	}
*/
/*	int main()
	{
		int a[5] = { 1, 2, 3, 4, 5 };
		int *ptr = (int *)(&a + 1);
		printf( "%d,%d", *(a + 1), *(ptr - 1));
		*(a + 1)= a ������Ԫ�ص�ַ +1 ���ڵڶ���Ԫ�ص�ַ �����ú� Ϊ�ڶ���Ԫ�� 2
		*(ptr -1) = (&a + 1)��������a����ĵ�ַǿ������ת���� int * ָ�����ʹ�ŵ� ptr����
		ptr - 1 ���ڵ�ַ������һ�� �൱�ڷ��� a ���һ��Ԫ��
		return 0;
	}
*/
//���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
//����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
//��֪���ṹ��Test���͵ı�����С��20���ֽ�
/*
int main()
{
	printf("%p\n", p + 0x1);//0x1=1 ����ָ��һ���ṹ��Ĵ�С 20�ֽ�  0x100000 + 20=0x100014
	printf("%p\n", (unsigned long)p + 0x1); // ����� p ת�����޷��ų����� =  0x100000 + 1 =0x100001
	printf("%p\n", (unsigned int*)p + 0x1); // ����� p ת�����޷�������ָ��
											// + 1 ���ڼ�һ��ָ���С 4 �ֽ� =  0x100000 + 4 = 0x100004
	return 0;
}*/
/*
int main()
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	ptr1����ָ������ a �ĺ���Ŀռ� -1 ����� 4
	ptr2����ָ���׵�ַ���һ��Ԫ�� 2 ǿ��ת���� int *����
	4  2
	return 0;
}*/
/*
int main()
{
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
	{ (0, 1), (2, 3), (4, 5) } �Ƕ��ű��ʽ ֻ��ʼ���� 1 3 5 ���ಹ 0
	�����ʽΪ��{{1,3},{5,0},{0,0}};
	int* p;
	p = a[0]; ����һ����Ԫ�ص�ַ;
	printf("%d", p[0]); p[0]=*(p+0)����һ����Ԫ�ص�ַ
	return 0;
}*/
/*
int main()
{									     p2	   a2
	int a[5][5];     00000 00000 00000 00000 00000
	int(*p)[4];		 p   p1   p2   p3	p4		    a[4][2]
	p =  a; �׵�ַpָ������ĸ�Ԫ�� ÿ��һi�������ĸ�Ԫ��  p[4][2]=*(*(p+4)+2) 
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); 
			&p[4][2] - &a[4][2] �м�����ĸ�Ԫ�� = -4
			%p��ӡ��ʱ����Ǵ�ӡ�޷����� -4�浽�ڴ���ǲ��� ��ֱ�Ӵ�ӡ
	return 0;
}*/
/*
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1); ָ�����������ַ���һ��λ��
	int* ptr2 = (int*)(*(aa + 1)); aa�׵�ַ +1 ����ָ��ڶ��е�һ��Ԫ��
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));  10 5
	return 0;
}
*/
/*
int main()
{
	char* a[] = { "work","at","alibaba" }; ��������ָ�� ��������������ַ 
	char** pa = a; ����ָ������ ����a ��һ��ָ��ĵ�ַ
	pa++;			����һ�� char * ��λ�� ���� �ڶ���Ԫ���׵�ַ
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
