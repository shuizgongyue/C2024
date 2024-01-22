#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string>

// strlen	����ʵ�ַ�ʽ   ָ����ַ�������Ҫ�� \0 ���� ����ֵ���޷�����
int my_strlen1(char* arr)
{
	int tmp = 0;
	while (*arr++) //��������ʽ
	{
		tmp++;
	}
	return tmp;
}
int my_strlen2(char* arr)
{
	//�ݹ���ʽ
	if (*arr != '\0')
		return 1 + my_strlen2(arr + 1);
	else
		return 0;
}
int my_strlen3(char* arr)
{
	//ָ�� �� ָ��
	char* tmp = arr;
	while (*arr++)
	{
		;
	}
	return (int)(arr - tmp - 1); // arr ����ָ�� \0  ������Ҫ��һ;
}

int main()
{
	char arr[] = "abcdef";
	
	printf("%d", my_strlen3(arr));
	return 0;
}


int main()
{
	if (strlen("abc") - strlen("abcdef") > 0)
	{
		printf("hehe"); // ��ӡ�Ǻ� strlen ��������ֵ���޷���ֵ  �޷�����һ������0
	}
	else
	{
		printf("haha");
	}
	return 0;
}

/*	strcpy  �ַ�������    ����ֵ��Ŀ�ĵس�ʼֵ�� ��ַ Դ�ַ������� \0 ����
 �ú����ὫԴ�ַ��� \0������Ŀ��ռ� ����Ŀ��ռ�����㹻���ܷ���Դ�ַ�   
 ģ��ʵ�ָú��� */
#include <assert.h>
char* my_strcpy(char* arr1, const char* arr2)
{
	assert(arr1  && arr2); // ���� �ж��ǲ��ǿ�ָ��
	char* ret = arr1;	   // �ѳ�ʼ��ַ��ֵ��һ����ʱ����
	//     �� arr2 ���Ƶ� arr1 ������� \0
	while (*arr1++ = *arr2++)
	{

	}
	return ret;				// ���� arr1 ��ʼ��ַ
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "bit";
	strcpy(arr1, arr2);
	printf("%s\n", arr1);
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}

// strcat(char arr, char arr1) �� arr1׷�ӵ� arr���� 
// �������������� \0  Ŀ�ĵؿռ�����㹻�� �ܹ����� arr1

void my_strcat(char* arr1,const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1)  // *arr++ �������ѭ������ ����ֹͣ��ʱ��ָ�� \0 ���ڴ�++ û�и��ǵ�;
	{
		arr1++;
	}
	while (*arr1++ = *arr2++)
	{
		;
	}
	
}

int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "bit";
	//strcat(arr1, arr2);
	my_strcat(arr1, arr2);
	printf("%s", arr1);
	return 0;
}

// strcmp (char arr, char arr1)�Ƚ� �ַ��� ��С  arr �� arr1�Ƚϴ�С arr > arr1 ���� 1  arr < arr1 ���� -1 
//													arr = arr1 ���� 0;
int my_strcmp(char* arr1, char* arr2)
{
	while (*arr1 == *arr2)		// ����ĸ��ȾͿ�ʼѭ���Ƚ�
	{
		if (*arr1 == '\0')      // arr1 = \0 ˵�� arr2 Ҳ���� \0 ��ô˵����� ���� 0
			return 0;
		arr1++;
		arr2++;
	}
	if (*arr1 > *arr2)
		return 1;
	else
		return -1;
	// ���Ż�Ϊ��return (*arr1 - *arr2)
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdeg";
	//int tmp = strcmp(arr1, arr2);
	int tmp = my_strcmp(arr1, arr2);
	if (tmp > 0)
		printf("arr1 > arr2");
	else if (tmp < 0)
		printf("arr1 < arr2");
	else
		printf("arr = arr2");
	return 0;
}
// strncpy(char arr, char arr1 ,int num) �� arr1��ǰnum���ַ������� arr ���� arr �ĳ��ȴ��� num 
//				��ô������ĩβ׷�� \0 ��� arr1 �ĳ���С�� num �򿽱���Դ�ַ���֮����Ŀ��ĺ��׷�� \0��ֱ��num����
void my_strncpy(char* str1,const char* str2, int a)
{
	assert(str1 && str2);
	while (a)
	{
		if (*str2 != '\0')
		{
			*str1++ = *str2++;
			a--;
		}
		else
			break;
	}
	while (a)
	{
		*str1 = '\0';
		str1++;
		a--;
	}
	
}

int main()
{
	char str1[20] = "abcdeDjkhukj";
	char str2[] = "abcde";
	strncpy(str1, str2, 6);
	//my_strncpy(str1, str2, 7);
	printf("%s\n", str1);
	return 0;
}

// strncat (char* str1,const char* str2, int num)
// �� str2 ǰ num ���ַ�׷�ӵ� str1���沢�Զ��� \0 
// ��� num > arr2 �ĳ�����ô str2 ׷�����ֱ�Ӳ� \0 ����ܶ���� num;  
void my_strncat(char* arr,const char* arr2, int num)
{
	assert(arr && arr2);
	while (*arr)
	{
		arr++;
	}
	while (num && *arr2)
	{
			*arr = *arr2;
			arr++;
			arr2++;
			num--;
	}
	*arr = '\0';
}

int main()
{
	char arr1[30] = "qwerty";
	char arr2[] = "asdfgh";
	//strncat(arr1, arr2, 8);
	my_strncat(arr1, arr2, 10);
	printf("%s", arr1);
	return 0;
}

// unsigned int strncmp(const char* arr,const char* arr2, int num)  
//			�ַ����ȽϺ���  �Ƚ� arr  arr2 ǰ num ���ַ��� ASCII ��С
int my_strncmp(char* s1, char* s2, int a)
{
	assert(s1 && s2);
	while (a)
	{
		if (*s1 > *s2)
		{
			return 1;
		}
		else if (*s1 < *s2)
		{
			return -1;
		}
		else
		{
			if (!*s1 && !*s2)
			{
				break;
			}
			s1++;
			s2++;
			a--;
		}
	}
	return 0;
}

int main()
{
	char str1[] = "efg";
	char str2[] = "abcdefg";
	int tmp = my_strncmp(str1, str2, 4);
	if (tmp > 0)
		printf("str1 > str2");
	else if(tmp<0)
		printf("str1 < str2");
	else
		printf("str1 = str2");
	return 0;
}

// strstr (const char* arr1,const char* arr2)  
// �� arr1 ����� arr2 �ǲ������� arr1 ���ִ�; ��������򷵻� arr2 ��Ԫ���� arr1 �еĵ�ַ( ָ�� );
//  ���򷵻� ��ָ�� �� NULL��;
// abbbcdef   
// bbc  
char* my_strstr(const char* arr,const char* arr2)
{
	assert(arr && arr2);
	char* s1 = NULL;
	char* s2 = NULL;
	char* tmp = (char*)arr;
	while (*tmp)
	{
		s1 = tmp;
		s2 = (char*)arr2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return tmp; // �ҵ��ִ�
		}
		tmp++;
	}
	return NULL;  // �Ҳ���
}

int main()
{
	char arr1[] = "abbbcdef";
	char arr2[] = "bbc";
	char* tmp = my_strstr(arr1, arr2);
	if (tmp == NULL)
	{
		printf("No");
	}
	else
	{
		printf("%s", tmp);
	}
	return 0;
}
// char * strtok ( char * str, const char * sep ); ����
// sep�����Ǹ��ַ����������������ָ������ַ�����
// ��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı�ǡ�
// strtok�����ҵ�str�е���һ����ǣ��������� \0 ��β������һ��ָ�������ǵ�ָ�롣
//��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ���������ݲ��ҿ��޸ġ���
// strtok�����ĵ�һ��������Ϊ NULL ���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ�á�
// strtok�����ĵ�һ������Ϊ NULL ����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ����ǡ�
// ����ַ����в����ڸ���ı�ǣ��򷵻� NULL ָ�롣

int main()
{
	char arr[] = "w13155607036@outlook.com";
	char p[] = "@.";
	/*printf("%s\n", strtok(arr, p));
	printf("%s\n", strtok(NULL, p));
	printf("%s\n", strtok(NULL, p));*/
	char* ret = NULL;
	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	return 0;
}

#include <errno.h>
// char * strerror ( int errnum );
// ���ش����룬����Ӧ�Ĵ�����Ϣ��

int main()
{
	char* a = NULL;
	a = strerror(errno);
	printf("%s", a);
	FILE* pf = fopen("test.txt", "r"); // ���ļ�����
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno)); // ʧ�ܾʹ�ӡ��Ӧ������Ϣ
	}
	else
	{
		printf("�򿪳ɹ�");  
	}
	return 0;
}
// �ַ�ת������;
// tolower (int c)    תСд��ĸ
// toupper (int C)	  ת��д��ĸ

int main()
{
	char arr = 'a';
	printf("%c\n", toupper(arr));
	char tr[] = "I AM YOU HEFEIDAXUE";
	int i = 0;
	while (tr[i])
	{
		if (isupper(tr[i])) // �ж��ǲ��Ǵ�д�ַ�
		{
			tr[i] = tolower(tr[i]); // ת��ΪСд 
		}
		i++;
	}
	printf("%s", tr);
	return 0;
}	

//    �ڴ��������;
// void* memcpy(void* destination, const void* source, size_t num); ��������Ԫ��
//				Ŀ�ĵ�				Դ��ַ				�������ֽ�
// ����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
// ������������� '\0' ��ʱ�򲢲���ͣ������
// ���source��destination���κε��ص������ƵĽ������δ����ġ�

int main()
{
	int arr[] = {1,2,3,4};
	int ret[30] = { 5,6,7,8,9,10,11 };
	memcpy(ret, arr, sizeof(arr));
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", ret[i]);
	}
	return 0;
}

// void * memmove ( void * destination, const void * source, size_t num ); ��������Ԫ��
// ��memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص��ġ�
// ���Դ�ռ��Ŀ��ռ�����ص����͵�ʹ��memmove��������

int main()
{
	int arr[] = { 1,2,3,4 };
	int ret[30] = { 5,6,7,8,9,10,11 };
	memmove(arr + 2, arr, 8);// �� arr ǰ�˸��ֽڵ�Ԫ�� ������ arr������Ԫ�ؿ�ʼ��λ��
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

// int memcmp ( const void * ptr1, const void* ptr2,size_t num );
// �Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num��   �ֽ�
// prt1 �� prt2 �Ƚϴ�С prt1 > prt2 ���� 1  prt1 < prt2 ���� -1  prt1 = prt2 ���� 0;

int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int ret[] = { 1,2,3,8,9,10 };
	int b = memcmp(arr, ret, 12);
	if (b > 0)
		printf("prt1 > prt2");
	else if (b < 0)
		printf("prt1 < prt2");
	else
		printf("prt1 = prt2");
	return 0;
}

//memset   �����ڴ�Ϊһ�������ַ��� ���������� int ����
// void* memset(void* dest, int c, rsize_t count)
// dest  Ŀ�ĵ�    c ���õ��ַ�   count  ���ö��ٸ��ַ�(�ֽ�Ϊ��λ);

int main()
{
	char arr[10] = "";
	memset(arr, '*', 10); 
	int arr1[10] = { 0 };
	memset(arr1, 5, 12);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}