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
		printf("³ıÊı²»ÄÜÎª0\n");
		return 0;
	}
}

void CD()
{
	printf("********************\n");
	printf("**  1:¼Ó   2:¼õ   **\n");
	printf("**  3:³Ë   4:³ı   **\n");
	printf("****   0£ºerc  *****\n");
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
		printf("ÇëÑ¡Ôñ¹¦ÄÜ\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("ÇëÊäÁ½¸ö²ÎÊı\n");
			scanf("%d%d", &x, &y);
			ret = arr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("ÍË³ö³ÌĞò\n");
		}
		else
		{
			printf("Ñ¡Ôñ´íÎóÖØĞÂÑ¡Ôñ\n");
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
		printf("é™¤æ•°ä¸èƒ½ä¸º0\n");
		return 0;
	}
}

void CD()
{
	printf("********************\n");
	printf("**  1:åŠ    2:å‡   **\n");
	printf("**  3:ä¹˜   4:é™¤   **\n");
	printf("****   0ï¼šerc  *****\n");
	printf("********************\n");
}

int main()
{
	int x = 0, y = 0, ret = 0;
	int input = 0;
	int(*arr[])(int, int) = { 0,add,sub,mul,div };       // æŒ‡å‘å‡½æ•°æŒ‡é’ˆæ•°ç»„çš„æŒ‡é’ˆ
	
	do
	{
		CD();
		printf("è¯·é€‰æ‹©åŠŸèƒ½\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("è¯·è¾“ä¸¤ä¸ªå‚æ•°\n");
			scanf("%d%d", &x, &y);
			ret = arr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("é€€å‡ºç¨‹åº\n");
		}
		else
		{
			printf("é€‰æ‹©é”™è¯¯é‡æ–°é€‰æ‹©\n");
		}
	} while (input);
	return 0;
}
>>>>>>> 2b820f0f7eb66ab7b4395d572a075fc8b822a0b5
