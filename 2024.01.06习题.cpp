#include <stdio.h>

//static inline volatile

//int main()
//{
//	int a = 1;
//	char* p = (char*) & a;
//	if (*p == 1)
//	{
//		printf("小");
//	}
//	else
//	{
//		printf("大");
//	}
//	return 0;
//}
//  下列会打印什么
		//int main()
		//{
		//	char a = -1;
		//	 10000000000000000000000000000001		原
		//	 11111111111111111111111111111110		反
		//	 11111111111111111111111111111111		补
		//	 a = 11111111                         
		//	以打印整形 需要整形提升
		//	 11111111111111111111111111111111		提升后 求源码打印
		//	 原码为：10000000000000000000000000000001 = -1
		//	signed char b = -1;
		//	 10000000000000000000000000000001		原
		//	 11111111111111111111111111111110		反
		//	 11111111111111111111111111111111		补
		//	 a = 11111111                         
		//	 以打印整形 需要整形提升
		//	 11111111111111111111111111111111		提升后 求源码打印
		//	 原码为：10000000000000000000000000000001 = -1
		//	unsigned char c = -1;
		//	 10000000000000000000000000000001		原
		//	 11111111111111111111111111111110		反
		//	 11111111111111111111111111111111		补
		//	 c = 11111111
		//	 以打印整形 需要整形提升   无符号数补0;
		//	 00000000000000000000000011111111
		//	 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 255    
		//	 提升后 以 整数形式打印 符号位为0为正数 原反补码都相同 = 255
		//	printf("%d %d %d ", a, b, c);
		//	return 0;
		//}


// 打印结果是什么
	//int main()
	//{
	//	char a = -128;
	//			//char a = -128;
	//			// -128 = 10000000000000000000000010000000  原码
	//			//		  11111111111111111111111101111111  反码
	//			//		  11111111111111111111111110000000  补码
	//			// char a = 10000000  二进制
	//			//  整形提升后 11111111111111111111111110000000
	//			//  无符号打印 无符号数 原码反码补码相同 就是 11111111111111111111111110000000 
	//			// 11111111111111111111111110000000 = 4,294,967,168
	//	printf("%u ", a);
	//	return 0;
	//}

			//int main()
			//{
			//	char a = 128;
			//			128 = 00000000000000000000000010000000;
			//			a = 10000000;
			//			整形提升 : 11111111111111111111111110000000 = 4,294,967,168;
			//	printf("%u\n", a);
			//	return 0;
			//}

		//int main()
		//{
		//	int i = -20;
		//		i = 10000000000000000000000000010100  原
		//			11111111111111111111111111101011  反
		//			11111111111111111111111111101100  补
		//	unsigned  int  j = 10;
		//		j = 00000000000000000000000000001010;

		//		11111111111111111111111111101100  补
		//		00000000000000000000000000001010  
		//		11111111111111111111111111110110   补
		//		11111111111111111111111111110101   反
		//		10000000000000000000000000001010   原
		//			= -10
		//	printf("%d\n", i + j);
		//	//按照补码的形式进行运算，最后格式化成为有符号整数
		//	return 0;
		//}

		//int main()
		//{
		//	unsigned int i;
		//	for (i = 9; i >= 0; i--)
		//	{
		//		printf("%u\n", i);
		//	}
		//	9 - 0  死循环  因为是无符号的 i 所以 i 永远为正 不可能为负 随意死循环;
		//	return 0;
		//}
#include <string.h>
				//int main()
				//{
				//	char a[1000];   char 类型的数据取值范围为： - 128 - 127
				//					unsigned char范围为：0 - 255;
				//	int i;
				//	for (i = 0; i < 1000; i++)
				//	{
				//		这里把 0 - 999放到 a 的每个字符里面去 超过限值需进行截断
				//		a[i] = -1 - i;
				//	}
				//	printf("%d", strlen(a));
				//	strlen 求长度 遇到 \0 停止 在 a 中 因为截断的原因 所以开始的值为 - 128 - 127
				//		最后为 0 而 \0 的ASCII 码值为 0 所以 计算的是 - 128 - 127的长度 为 255;
				//	return 0;
				//}

				//unsigned char i = 0;  定义一个无符号的全局的 char i
				//int main()
				//{
				//	for (i = 0; i <= 255; i++)
				//	{
				//		因为 unsigned char i 的值 范围为 0-255 一直达到条件 所以 恒成立 形成死循环
				//		printf("hello world\n");
				//	}
				//	return 0;
				//}