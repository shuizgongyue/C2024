#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (* (void (*)() ) 0 )(); �� 0 ǿ������תΪ void ��*����������ָ������ 0����һ������ָ��ĵ�ַ
						// ������ 0 ��ַ���ĺ���

// void (*signal(int, void(*)(int)))(int);  
// signal ��һ���������� ����������һ���� int һ���Ǻ���ָ�룬���ָ������� int ���� ������ void���ͣ�
// signal �����ķ���������һ������ָ�� ���ָ������� int ���� ������ void����;


// ����ָ������   -- ��һ������ ���� ��������ָ������ָ��       �г�ת�Ʊ�
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
		printf("��������Ϊ0");
		return 0;
	}
}
/*	int main()
	{
		int(*arr[4])(int, int) = { sum,sum1,sum2,sum3 }; // ����ָ������
		 arr ��һ������ ������4��Ԫ�� Ԫ�ص������� ָ�뺯�� ���������� int ;
		return 0;
	}*/

/*	char* my_strcpy(char* dest, const char* src);

	 дһ��ָ�� pf �ܺ�ָ�� my_strcpy;
	
	char* (*pf)(char* dest, const char* src) = my_strcpy;
	
	дһ������ָ������ pfarr �ܹ�����ĸ� my_strcpy ������ַ;
	
	char* (*pfarr[4])(char* dest, const char* src) = { my_strcpy };
*/
void CD()
{
	printf("********************\n");
	printf("**  1:��   2:��   **\n");
	printf("**  3:��   4:��   **\n");
	printf("****   0��erc  *****\n");
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
				printf("��ѡ����\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					printf("���������\n");                     ÿ��ѡ�񶼻���� �����ӿ�� Ҫ�Ż�
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 2:
					printf("���������\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 3:
					printf("���������\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 4:
					printf("���������\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 0:
					printf("�����˳�������\n");
					break;
				default:
					printf("ѡ�����\n");
					break;
				}
			} while (input);
			return 0;
		}*/

// �Ż���    �ص����� -- �ص���������һ��ͨ������ָ����õĺ�����
// �����Ѻ�����ָ�루��ַ����Ϊ�������ݸ���һ��
// �����������ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú���
// ��ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ�������һ�����õģ����ڶԸ��¼���������
// ����Ӧ��
 void cool (int (*pf)(int,int))          // �ص�����
{
	int x = 0, y = 0;
	printf("���������\n");
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
				printf("��ѡ����\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					cool(sum);                //ͨ����������ʽ ����ѡ�� ����ͬ�ĺ��� ʵ�ֹ���
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
					printf("�����˳�������\n");
					break;
				default:
					printf("ѡ�����\n");
					break;
				}
			} while (input);
			return 0;
		} 
*/

 // qsort ��������(���������κ����͵�����)   
 //			�������ĸ�������1������ı��� 2�������ĸ��� 3�����������Ĵ�С 
 //			4������ĺ���  ���������Ƚ�����Ԫ�صĺ�������������������κ�ֵ
 //			����ֱ���޸Ĵ�������������
 //			�������ĸ�ʽ����Ϊ�� int (������)����(const void* e1, const void* e2)
 //         ����ȽϺ������ص㣺����һ��Ԫ�� < �ڶ���Ԫ�� ���� <0�� 
 //								����һ��Ԫ�� = �ڶ���Ԫ�� ���� 0,
 //								����һ��Ԫ�� > �ڶ���Ԫ�� ���� >0

 int cmp_int(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));     // ���εıȽ��㷨
 }
 void tst_int()
 {
	 int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	 int sz = sizeof(arr) / sizeof(arr[0]);
	 qsort(arr, sz, sizeof(arr[0]), cmp_int);  // �����ε�����
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%d ", arr[i]);
	 }
 }

 int cmp_float(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));    // �����εıȽ��㷨
 }
 void tst_float()
 {
	 float arr1[] = { 5.0,4.0,3.0,2.0,1.0,0.0 };
	 int sz = sizeof(arr1) / sizeof(arr1[0]);
	 qsort(arr1, sz, sizeof(arr1[0]), cmp_float);  // �Ը�����������
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
	 return ((struct ryxx*)e1)->age - ((struct ryxx*)e2)->age; // �Խṹ��Ԫ�صıȽ��㷨
 }
 void tst_struct_age()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // �Խṹ��ıȽ�;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_age);					// �ȽϽṹ�����һ����������;
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%s %d  ", s[i].name, s[i].age);
	 }
 }
 int cmp_struct_name(const void* e1, const void* e2)
 {
	 //���ֵıȽϾ��ǱȽ��ַ���
	 //�ַ����Ƚϲ���ֱ���� > < = ���Ƚϣ� Ӧ��ʹ�ú���strcmp������;
	 return strcmp(((struct ryxx*)e1)->name, ((struct ryxx*)e2)->name); // �Խṹ��Ԫ�� ���ֵ�����
 }
 void tst_struct_name()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // �Խṹ��ıȽ�;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_name);					// �ȽϽṹ�����һ����������;
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