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
		printf("��������Ϊ0\n");
		return 0;
	}
}

void CD()
{
	printf("********************\n");
	printf("**  1:��   2:��   **\n");
	printf("**  3:��   4:��   **\n");
	printf("****   0��erc  *****\n");
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
		printf("��ѡ����\n");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("������������\n");
			scanf("%d%d", &x, &y);
			ret = arr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�����\n");
		}
		else
		{
			printf("ѡ���������ѡ��\n");
		}
	} while (input);
	return 0;
}