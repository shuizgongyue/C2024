<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	if (y != 0)
		return x / y;
	else
	{
		printf("除数不能为0\n");
		return 0;
	}
}

void CD()
{
	printf("********************\n");
	printf("**  1:加   2:减   **\n");
	printf("**  3:乘   4:除   **\n");
	printf("****   0：erc  *****\n");
	printf("********************\n");
}

int main()
{
	int x = 0, y = 0, ret = 0;
	int input = 0;
	int(*arr[])(int, int) = { 0,add,sub,mul,div };
	
	do
	{
		CD();
		printf("请选择功能\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输两个参数\n");
			scanf("%d%d", &x, &y);
			ret = arr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出程序\n");
		}
		else
		{
			printf("选择错误重新选择\n");
		}
	} while (input);
	return 0;
}
=======
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	if (y != 0)
		return x / y;
	else
	{
		printf("闄ゆ暟涓嶈兘涓�0\n");
		return 0;
	}
}

void CD()
{
	printf("********************\n");
	printf("**  1:鍔�   2:鍑�   **\n");
	printf("**  3:涔�   4:闄�   **\n");
	printf("****   0锛歟rc  *****\n");
	printf("********************\n");
}

int main()
{
	int x = 0, y = 0, ret = 0;
	int input = 0;
	int(*arr[])(int, int) = { 0,add,sub,mul,div };       // 鎸囧悜鍑芥暟鎸囬拡鏁扮粍鐨勬寚閽�
	
	do
	{
		CD();
		printf("璇烽�夋嫨鍔熻兘\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("璇疯緭涓や釜鍙傛暟\n");
			scanf("%d%d", &x, &y);
			ret = arr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("閫�鍑虹▼搴廫n");
		}
		else
		{
			printf("閫夋嫨閿欒閲嶆柊閫夋嫨\n");
		}
	} while (input);
	return 0;
}
>>>>>>> 2b820f0f7eb66ab7b4395d572a075fc8b822a0b5
