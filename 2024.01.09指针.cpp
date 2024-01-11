<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (* (void (*)() ) 0 )(); °Ñ 0 Ç¿ÖÆÀàĞÍ×ªÎª void £¨*£©£¨£©º¯ÊıÖ¸ÕëÀàĞÍ 0¾ÍÊÇÒ»¸öº¯ÊıÖ¸ÕëµÄµØÖ·
						// ×îºóµ÷ÓÃ 0 µØÖ·´¦µÄº¯Êı

// void (*signal(int, void(*)(int)))(int);  
// signal ÊÇÒ»¸öº¯ÊıÉùÃ÷ ²ÎÊıÓĞÁ½¸öÒ»¸öÊÇ int Ò»¸öÊÇº¯ÊıÖ¸Õë£¬Õâ¸öÖ¸Õë²ÎÊıÊÇ int ÀàĞÍ ·µ»ØÊÇ voidÀàĞÍ£»
// signal º¯ÊıµÄ·µ»ØÀàĞÍÊÇÒ»¸öº¯ÊıÖ¸Õë Õâ¸öÖ¸Õë²ÎÊıÊÇ int ÀàĞÍ ·µ»ØÊÇ voidÀàĞÍ;


// º¯ÊıÖ¸ÕëÊı×é   -- ÊÇÒ»¸öÊı×é ÀïÃæ ÀïÃæ´æ·ÅÁËÖ¸Ïòº¯ÊıµÄÖ¸Õë       ÓĞ³Æ×ªÒÆ±í
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
		printf("³ıÊı²»ÄÜÎª0");
		return 0;
	}
}
/*	int main()
	{
		int(*arr[4])(int, int) = { sum,sum1,sum2,sum3 }; // º¯ÊıÖ¸ÕëÊı×é
		 arr ÊÇÒ»¸öÊı×é ÀïÃæÓĞ4¸öÔªËØ ÔªËØµÄÀàĞÍÊÇ Ö¸Õëº¯Êı ·µ»ØÀàĞÍÊÇ int ;
		return 0;
	}*/

/*	char* my_strcpy(char* dest, const char* src);

	 Ğ´Ò»¸öÖ¸Õë pf ÄÜºóÖ¸Ïò my_strcpy;
	
	char* (*pf)(char* dest, const char* src) = my_strcpy;
	
	Ğ´Ò»¸öº¯ÊıÖ¸ÕëÊı×é pfarr ÄÜ¹»´æ·ÅËÄ¸ö my_strcpy º¯ÊıµØÖ·;
	
	char* (*pfarr[4])(char* dest, const char* src) = { my_strcpy };
*/
void CD()
{
	printf("********************\n");
	printf("**  1:¼Ó   2:¼õ   **\n");
	printf("**  3:³Ë   4:³ı   **\n");
	printf("****   0£ºerc  *****\n");
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
				printf("ÇëÑ¡Ôñ¹¦ÄÜ\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					printf("ÇëÊäÈë²ÎÊı\n");                     Ã¿¸öÑ¡Ôñ¶¼»á³öÏÖ »á³öÏÖÓ¿Óà ÒªÓÅ»¯
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 2:
					printf("ÇëÊäÈë²ÎÊı\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 3:
					printf("ÇëÊäÈë²ÎÊı\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 4:
					printf("ÇëÊäÈë²ÎÊı\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 0:
					printf("ÄãÒÔÍË³ö¼ÆËãÆ÷\n");
					break;
				default:
					printf("Ñ¡Ôñ´íÎó\n");
					break;
				}
			} while (input);
			return 0;
		}*/

// ÓÅ»¯ºó    »Øµ÷º¯Êı -- »Øµ÷º¯Êı¾ÍÊÇÒ»¸öÍ¨¹ıº¯ÊıÖ¸Õëµ÷ÓÃµÄº¯Êı¡£
// Èç¹ûÄã°Ñº¯ÊıµÄÖ¸Õë£¨µØÖ·£©×÷Îª²ÎÊı´«µİ¸øÁíÒ»¸ö
// º¯Êı£¬µ±Õâ¸öÖ¸Õë±»ÓÃÀ´µ÷ÓÃÆäËùÖ¸ÏòµÄº¯ÊıÊ±£¬ÎÒÃÇ¾ÍËµÕâÊÇ»Øµ÷º¯Êı¡£»Øµ÷º¯Êı²»ÊÇÓÉ¸Ãº¯Êı
// µÄÊµÏÖ·½Ö±½Óµ÷ÓÃ£¬¶øÊÇÔÚÌØ¶¨µÄÊÂ¼ş»òÌõ¼ş·¢ÉúÊ±ÓÉÁíÍâµÄÒ»·½µ÷ÓÃµÄ£¬ÓÃÓÚ¶Ô¸ÃÊÂ¼ş»òÌõ¼ş½ø
// ĞĞÏìÓ¦¡£
 void cool (int (*pf)(int,int))          // »Øµ÷º¯Êı
{
	int x = 0, y = 0;
	printf("ÇëÊäÈë²ÎÊı\n");
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
				printf("ÇëÑ¡Ôñ¹¦ÄÜ\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					cool(sum);                //Í¨¹ıº¯ÊıµÄĞÎÊ½ ¸ù¾İÑ¡Ôñ ´«²»Í¬µÄº¯Êı ÊµÏÖ¹¦ÄÜ
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
					printf("ÄãÒÔÍË³ö¼ÆËãÆ÷\n");
					break;
				default:
					printf("Ñ¡Ôñ´íÎó\n");
					break;
				}
			} while (input);
			return 0;
		} 
*/

 // qsort ¿ìËÙÅÅĞò(¿ÉÒÔÅÅĞòÈÎºÎÀàĞÍµÄÊı¾İ)   
 //			ÀïÃæÓĞËÄ¸ö²ÎÊı£¨1£ºÅÅĞòµÄ±äÁ¿ 2£º±äÁ¿µÄ¸öÊı 3£º±äÁ¿²ÎÊıµÄ´óĞ¡ 
 //			4£ºÅÅĞòµÄº¯Êı  º¯ÊıÓÃÀ´±È½ÏÁ½¸öÔªËØµÄº¯Êı¡£Õâ¸öº¯Êı²»·µ»ØÈÎºÎÖµ
 //			µ«»ØÖ±½ÓĞŞ¸Ä´«ÈëµÄÅÅĞò±äÁ¿£»
 //			ÅÅĞòº¯ÊıµÄ¸ñÊ½±ØĞëÎª£º int (±äÁ¿Ãû)²ÎÊı(const void* e1, const void* e2)
 //         Õâ¸ö±È½Ïº¯ÊıµÄÌØµã£ºµ±µÚÒ»¸öÔªËØ < µÚ¶ş¸öÔªËØ ·µ»Ø <0£¬ 
 //								µ±µÚÒ»¸öÔªËØ = µÚ¶ş¸öÔªËØ ·µ»Ø 0,
 //								µ±µÚÒ»¸öÔªËØ > µÚ¶ş¸öÔªËØ ·µ»Ø >0

 int cmp_int(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));     // ÕûĞÎµÄ±È½ÏËã·¨
 }
 void tst_int()
 {
	 int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	 int sz = sizeof(arr) / sizeof(arr[0]);
	 qsort(arr, sz, sizeof(arr[0]), cmp_int);  // ¶ÔÕûĞÎµÄÅÅĞò
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%d ", arr[i]);
	 }
 }

 int cmp_float(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));    // ¸¡µãĞÎµÄ±È½ÏËã·¨
 }
 void tst_float()
 {
	 float arr1[] = { 5.0,4.0,3.0,2.0,1.0,0.0 };
	 int sz = sizeof(arr1) / sizeof(arr1[0]);
	 qsort(arr1, sz, sizeof(arr1[0]), cmp_float);  // ¶Ô¸¡µãÊıµÄÅÅĞò
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
	 return ((struct ryxx*)e1)->age - ((struct ryxx*)e2)->age; // ¶Ô½á¹¹ÌåÔªËØµÄ±È½ÏËã·¨
 }
 void tst_struct_age()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // ¶Ô½á¹¹ÌåµÄ±È½Ï;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_age);					// ±È½Ï½á¹¹ÌåµÄÖĞÒ»¸ö²ÎÊıÅÅĞò;
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%s %d  ", s[i].name, s[i].age);
	 }
 }
 int cmp_struct_name(const void* e1, const void* e2)
 {
	 //Ãû×ÖµÄ±È½Ï¾ÍÊÇ±È½Ï×Ö·û´®
	 //×Ö·û´®±È½Ï²»ÄÜÖ±½ÓÓÃ > < = À´±È½Ï£» Ó¦¸ÃÊ¹ÓÃº¯ÊıstrcmpÀ´½øĞĞ;
	 return strcmp(((struct ryxx*)e1)->name, ((struct ryxx*)e2)->name); // ¶Ô½á¹¹ÌåÔªËØ Ãû×ÖµÄÅÅĞò
 }
 void tst_struct_name()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // ¶Ô½á¹¹ÌåµÄ±È½Ï;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_name);					// ±È½Ï½á¹¹ÌåµÄÖĞÒ»¸ö²ÎÊıÅÅĞò;
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
=======
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (* (void (*)() ) 0 )(); æŠŠ 0 å¼ºåˆ¶ç±»å‹è½¬ä¸º void ï¼ˆ*ï¼‰ï¼ˆï¼‰å‡½æ•°æŒ‡é’ˆç±»å‹ 0å°±æ˜¯ä¸€ä¸ªå‡½æ•°æŒ‡é’ˆçš„åœ°å€
						// æœ€åè°ƒç”¨ 0 åœ°å€å¤„çš„å‡½æ•°

// void (*signal(int, void(*)(int)))(int);  
// signal æ˜¯ä¸€ä¸ªå‡½æ•°å£°æ˜ å‚æ•°æœ‰ä¸¤ä¸ªä¸€ä¸ªæ˜¯ int ä¸€ä¸ªæ˜¯å‡½æ•°æŒ‡é’ˆï¼Œè¿™ä¸ªæŒ‡é’ˆå‚æ•°æ˜¯ int ç±»å‹ è¿”å›æ˜¯ voidç±»å‹ï¼›
// signal å‡½æ•°çš„è¿”å›ç±»å‹æ˜¯ä¸€ä¸ªå‡½æ•°æŒ‡é’ˆ è¿™ä¸ªæŒ‡é’ˆå‚æ•°æ˜¯ int ç±»å‹ è¿”å›æ˜¯ voidç±»å‹;


// å‡½æ•°æŒ‡é’ˆæ•°ç»„   -- æ˜¯ä¸€ä¸ªæ•°ç»„ é‡Œé¢ é‡Œé¢å­˜æ”¾äº†æŒ‡å‘å‡½æ•°çš„æŒ‡é’ˆ       æœ‰ç§°è½¬ç§»è¡¨
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
		printf("é™¤æ•°ä¸èƒ½ä¸º0");
		return 0;
	}
}
/*	int main()
	{
		int(*arr[4])(int, int) = { sum,sum1,sum2,sum3 }; // å‡½æ•°æŒ‡é’ˆæ•°ç»„
		 arr æ˜¯ä¸€ä¸ªæ•°ç»„ é‡Œé¢æœ‰4ä¸ªå…ƒç´  å…ƒç´ çš„ç±»å‹æ˜¯ æŒ‡é’ˆå‡½æ•° è¿”å›ç±»å‹æ˜¯ int ;
		return 0;
	}*/

/*	char* my_strcpy(char* dest, const char* src);

	 å†™ä¸€ä¸ªæŒ‡é’ˆ pf èƒ½åæŒ‡å‘ my_strcpy;
	
	char* (*pf)(char* dest, const char* src) = my_strcpy;
	
	å†™ä¸€ä¸ªå‡½æ•°æŒ‡é’ˆæ•°ç»„ pfarr èƒ½å¤Ÿå­˜æ”¾å››ä¸ª my_strcpy å‡½æ•°åœ°å€;
	
	char* (*pfarr[4])(char* dest, const char* src) = { my_strcpy };
*/
void CD()
{
	printf("********************\n");
	printf("**  1:åŠ    2:å‡   **\n");
	printf("**  3:ä¹˜   4:é™¤   **\n");
	printf("****   0ï¼šerc  *****\n");
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
				printf("è¯·é€‰æ‹©åŠŸèƒ½\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					printf("è¯·è¾“å…¥å‚æ•°\n");                     æ¯ä¸ªé€‰æ‹©éƒ½ä¼šå‡ºç° ä¼šå‡ºç°æ¶Œä½™ è¦ä¼˜åŒ–
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 2:
					printf("è¯·è¾“å…¥å‚æ•°\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 3:
					printf("è¯·è¾“å…¥å‚æ•°\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 4:
					printf("è¯·è¾“å…¥å‚æ•°\n");
					scanf("%d %d", &x, &y);
					printf("%d\n", arr[input](x, y));
					break;
				case 0:
					printf("ä½ ä»¥é€€å‡ºè®¡ç®—å™¨\n");
					break;
				default:
					printf("é€‰æ‹©é”™è¯¯\n");
					break;
				}
			} while (input);
			return 0;
		}*/

// ä¼˜åŒ–å    å›è°ƒå‡½æ•° -- å›è°ƒå‡½æ•°å°±æ˜¯ä¸€ä¸ªé€šè¿‡å‡½æ•°æŒ‡é’ˆè°ƒç”¨çš„å‡½æ•°ã€‚
// å¦‚æœä½ æŠŠå‡½æ•°çš„æŒ‡é’ˆï¼ˆåœ°å€ï¼‰ä½œä¸ºå‚æ•°ä¼ é€’ç»™å¦ä¸€ä¸ª
// å‡½æ•°ï¼Œå½“è¿™ä¸ªæŒ‡é’ˆè¢«ç”¨æ¥è°ƒç”¨å…¶æ‰€æŒ‡å‘çš„å‡½æ•°æ—¶ï¼Œæˆ‘ä»¬å°±è¯´è¿™æ˜¯å›è°ƒå‡½æ•°ã€‚å›è°ƒå‡½æ•°ä¸æ˜¯ç”±è¯¥å‡½æ•°
// çš„å®ç°æ–¹ç›´æ¥è°ƒç”¨ï¼Œè€Œæ˜¯åœ¨ç‰¹å®šçš„äº‹ä»¶æˆ–æ¡ä»¶å‘ç”Ÿæ—¶ç”±å¦å¤–çš„ä¸€æ–¹è°ƒç”¨çš„ï¼Œç”¨äºå¯¹è¯¥äº‹ä»¶æˆ–æ¡ä»¶è¿›
// è¡Œå“åº”ã€‚
 void cool (int (*pf)(int,int))          // å›è°ƒå‡½æ•°
{
	int x = 0, y = 0;
	printf("è¯·è¾“å…¥å‚æ•°\n");
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
				printf("è¯·é€‰æ‹©åŠŸèƒ½\n");
				scanf("%d", &input);
				switch (input)
				{
				case 1:
					cool(sum);                //é€šè¿‡å‡½æ•°çš„å½¢å¼ æ ¹æ®é€‰æ‹© ä¼ ä¸åŒçš„å‡½æ•° å®ç°åŠŸèƒ½
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
					printf("ä½ ä»¥é€€å‡ºè®¡ç®—å™¨\n");
					break;
				default:
					printf("é€‰æ‹©é”™è¯¯\n");
					break;
				}
			} while (input);
			return 0;
		} 
*/

 // qsort å¿«é€Ÿæ’åº(å¯ä»¥æ’åºä»»ä½•ç±»å‹çš„æ•°æ®)   
 //			é‡Œé¢æœ‰å››ä¸ªå‚æ•°ï¼ˆ1ï¼šæ’åºçš„æ•°ç»„é¦–å…ƒç´ åœ°å€ 2ï¼šæ’åºæ•°ç»„å…ƒç´ çš„ä¸ªæ•° 3ï¼šå˜é‡å‚æ•°çš„å¤§å°  å•ä½å­—èŠ‚
 //			4ï¼šæ’åºçš„å‡½æ•°  å‡½æ•°ç”¨æ¥æ¯”è¾ƒä¸¤ä¸ªå…ƒç´ çš„å‡½æ•°ï¼Œï¼Œéœ€è‡ªå·±å®ç°ã€‚è¿™ä¸ªå‡½æ•°ä¸è¿”å›ä»»ä½•å€¼
 //			ä½†å›ç›´æ¥ä¿®æ”¹ä¼ å…¥çš„æ’åºå˜é‡ï¼›
 //			æ’åºå‡½æ•°çš„æ ¼å¼å¿…é¡»ä¸ºï¼š int (å˜é‡å)å‚æ•°(const void* e1, const void* e2)
 //         è¿™ä¸ªæ¯”è¾ƒå‡½æ•°çš„ç‰¹ç‚¹ï¼šå½“ç¬¬ä¸€ä¸ªå…ƒç´  < ç¬¬äºŒä¸ªå…ƒç´  è¿”å› <0ï¼Œ 
 //								å½“ç¬¬ä¸€ä¸ªå…ƒç´  = ç¬¬äºŒä¸ªå…ƒç´  è¿”å› 0,
 //								å½“ç¬¬ä¸€ä¸ªå…ƒç´  > ç¬¬äºŒä¸ªå…ƒç´  è¿”å› >0

 int cmp_int(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));     // æ•´å½¢çš„æ¯”è¾ƒç®—æ³•
 }
 void tst_int()
 {
	 int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	 int sz = sizeof(arr) / sizeof(arr[0]);
	 qsort(arr, sz, sizeof(arr[0]), cmp_int);  // å¯¹æ•´å½¢çš„æ’åº
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%d ", arr[i]);
	 }
 }

 int cmp_float(const void* e1, const void* e2)
 {
	 return (*(int*)(e1)) - (*(int*)(e2));    // æµ®ç‚¹å½¢çš„æ¯”è¾ƒç®—æ³•
 }
 void tst_float()
 {
	 float arr1[] = { 5.0,4.0,3.0,2.0,1.0,0.0 };
	 int sz = sizeof(arr1) / sizeof(arr1[0]);
	 qsort(arr1, sz, sizeof(arr1[0]), cmp_float);  // å¯¹æµ®ç‚¹æ•°çš„æ’åº
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
	 return ((struct ryxx*)e1)->age - ((struct ryxx*)e2)->age; // å¯¹ç»“æ„ä½“å…ƒç´ çš„æ¯”è¾ƒç®—æ³•
 }
 void tst_struct_age()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // å¯¹ç»“æ„ä½“çš„æ¯”è¾ƒ;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_age);					// æ¯”è¾ƒç»“æ„ä½“çš„ä¸­ä¸€ä¸ªå‚æ•°æ’åº;
	 for (int i = 0; i < sz; i++)
	 {
		 printf("%s %d  ", s[i].name, s[i].age);
	 }
 }
 int cmp_struct_name(const void* e1, const void* e2)
 {
	 //åå­—çš„æ¯”è¾ƒå°±æ˜¯æ¯”è¾ƒå­—ç¬¦ä¸²
	 //å­—ç¬¦ä¸²æ¯”è¾ƒä¸èƒ½ç›´æ¥ç”¨ > < = æ¥æ¯”è¾ƒï¼› åº”è¯¥ä½¿ç”¨å‡½æ•°strcmpæ¥è¿›è¡Œ;
	 return strcmp(((struct ryxx*)e1)->name, ((struct ryxx*)e2)->name); // å¯¹ç»“æ„ä½“å…ƒç´  åå­—çš„æ’åº
 }
 void tst_struct_name()
 {
	 xx s[3] = { {"zhansan",30},{"wangwu",20},{"lisi",15} };    // å¯¹ç»“æ„ä½“çš„æ¯”è¾ƒ;
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_struct_name);					// æ¯”è¾ƒç»“æ„ä½“çš„ä¸­ä¸€ä¸ªå‚æ•°æ’åº;
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
>>>>>>> 2b820f0f7eb66ab7b4395d572a075fc8b822a0b5
