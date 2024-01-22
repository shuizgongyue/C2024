#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string>

// strlen	三种实现方式   指向的字符串必须要以 \0 结束 返回值是无符号数
int my_strlen1(char* arr)
{
	int tmp = 0;
	while (*arr++) //计数器形式
	{
		tmp++;
	}
	return tmp;
}
int my_strlen2(char* arr)
{
	//递归形式
	if (*arr != '\0')
		return 1 + my_strlen2(arr + 1);
	else
		return 0;
}
int my_strlen3(char* arr)
{
	//指针 减 指针
	char* tmp = arr;
	while (*arr++)
	{
		;
	}
	return (int)(arr - tmp - 1); // arr 最后会指向 \0  所以需要减一;
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
		printf("hehe"); // 打印呵呵 strlen 函数返回值是无符号值  无符号数一定大于0
	}
	else
	{
		printf("haha");
	}
	return 0;
}

/*	strcpy  字符串拷贝    返回值是目的地初始值的 地址 源字符必须以 \0 结束
 该函数会将源字符的 \0拷贝到目标空间 并且目标空间必须足够大，能放下源字符   
 模拟实现该函数 */
#include <assert.h>
char* my_strcpy(char* arr1, const char* arr2)
{
	assert(arr1  && arr2); // 断言 判断是不是空指针
	char* ret = arr1;	   // 把初始地址赋值给一个临时变量
	//     把 arr2 复制到 arr1 里面包含 \0
	while (*arr1++ = *arr2++)
	{

	}
	return ret;				// 返回 arr1 初始地址
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

// strcat(char arr, char arr1) 把 arr1追加到 arr后面 
// 两个参数必须有 \0  目的地空间必须足够大 能够放下 arr1

void my_strcat(char* arr1,const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1)  // *arr++ 如果放在循环条件 则在停止的时候指向 \0 后在次++ 没有覆盖掉;
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

// strcmp (char arr, char arr1)比较 字符串 大小  arr 和 arr1比较大小 arr > arr1 返回 1  arr < arr1 返回 -1 
//													arr = arr1 返回 0;
int my_strcmp(char* arr1, char* arr2)
{
	while (*arr1 == *arr2)		// 首字母相等就开始循环比较
	{
		if (*arr1 == '\0')      // arr1 = \0 说明 arr2 也等于 \0 那么说明相等 返回 0
			return 0;
		arr1++;
		arr2++;
	}
	if (*arr1 > *arr2)
		return 1;
	else
		return -1;
	// 可优化为：return (*arr1 - *arr2)
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
// strncpy(char arr, char arr1 ,int num) 把 arr1中前num个字符拷贝到 arr 里面 arr 的长度大于 num 
//				那么不会在末尾追加 \0 如果 arr1 的长度小于 num 则拷贝完源字符串之后，在目标的后边追加 \0，直到num个。
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
// 把 str2 前 num 个字符追加到 str1后面并自动补 \0 
// 如果 num > arr2 的长度那么 str2 追加完后直接补 \0 不会管多余的 num;  
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
//			字符串比较函数  比较 arr  arr2 前 num 个字符的 ASCII 大小
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
// 在 arr1 里查找 arr2 是不是属于 arr1 的字串; 如果属于则返回 arr2 首元素在 arr1 中的地址( 指针 );
//  否则返回 空指针 （ NULL）;
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
			return tmp; // 找到字串
		}
		tmp++;
	}
	return NULL;  // 找不到
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
// char * strtok ( char * str, const char * sep ); 函数
// sep参数是个字符串，定义了用作分隔符的字符集合
// 第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
// strtok函数找到str中的下一个标记，并将其用 \0 结尾，返回一个指向这个标记的指针。
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
// strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
// strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
// 如果字符串中不存在更多的标记，则返回 NULL 指针。

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
// 返回错误码，所对应的错误信息。

int main()
{
	char* a = NULL;
	a = strerror(errno);
	printf("%s", a);
	FILE* pf = fopen("test.txt", "r"); // 打开文件函数
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno)); // 失败就打印相应错误信息
	}
	else
	{
		printf("打开成功");  
	}
	return 0;
}
// 字符转换函数;
// tolower (int c)    转小写字母
// toupper (int C)	  转大写字母

int main()
{
	char arr = 'a';
	printf("%c\n", toupper(arr));
	char tr[] = "I AM YOU HEFEIDAXUE";
	int i = 0;
	while (tr[i])
	{
		if (isupper(tr[i])) // 判断是不是大写字符
		{
			tr[i] = tolower(tr[i]); // 转换为小写 
		}
		i++;
	}
	printf("%s", tr);
	return 0;
}	

//    内存操作函数;
// void* memcpy(void* destination, const void* source, size_t num); 拷贝任意元素
//				目的地				源地址				拷贝的字节
// 函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
// 这个函数在遇到 '\0' 的时候并不会停下来。
// 如果source和destination有任何的重叠，复制的结果都是未定义的。

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

// void * memmove ( void * destination, const void * source, size_t num ); 拷贝任意元素
// 和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的。
// 如果源空间和目标空间出现重叠，就得使用memmove函数处理。

int main()
{
	int arr[] = { 1,2,3,4 };
	int ret[30] = { 5,6,7,8,9,10,11 };
	memmove(arr + 2, arr, 8);// 把 arr 前八个字节的元素 拷贝到 arr第三个元素开始的位置
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

// int memcmp ( const void * ptr1, const void* ptr2,size_t num );
// 比较从ptr1和ptr2指针开始的num个   字节
// prt1 和 prt2 比较大小 prt1 > prt2 返回 1  prt1 < prt2 返回 -1  prt1 = prt2 返回 0;

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

//memset   设置内存为一个特殊字符； 不能作用于 int 类型
// void* memset(void* dest, int c, rsize_t count)
// dest  目的地    c 设置的字符   count  设置多少个字符(字节为单位);

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