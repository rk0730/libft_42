#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

#ifdef FT
# define F(name) ft_ ## name
#else
# define F(name) name
#endif

void	test_isalpha()
{
	printf("\nisalpha\n");
	printf("%d ", F(isalpha)('a'));
	printf("%d ", F(isalpha)('A'));
	printf("%d ", F(isalpha)('k'));
	printf("%d ", F(isalpha)('z'));
	printf("%d ", F(isalpha)(65));
	printf("%d ", F(isalpha)('1'));
	printf("%d ", F(isalpha)('0'));
	printf("\n");
}

void	test_isdigit()
{
	printf("\nisdigit\n");
	printf("%d ", F(isdigit)('1'));
	printf("%d ", F(isdigit)('2'));
	printf("%d ", F(isdigit)('a'));
	printf("%d ", F(isdigit)('\n'));
	printf("\n");
}

void	test_isalnum()
{
	printf("\nisalnum\n");
	printf("%d ", F(isalnum)('1'));
	printf("%d ", F(isalnum)('7'));
	printf("%d ", F(isalnum)('a'));
	printf("%d ", F(isalnum)('Z'));
	printf("%d ", F(isalnum)('\n'));
	printf("%d ", F(isalnum)('\0'));
	printf("%d ", F(isalnum)('\t'));
	printf("\n");
}

void	test_isascii()
{
	printf("\nisascii\n");
	printf("%d ", F(isascii)(' '));
	printf("%d ", F(isascii)('1'));
	printf("%d ", F(isascii)('a'));
	printf("%d ", F(isascii)('Z'));
	printf("%d ", F(isascii)('\n'));
	printf("%d ", F(isascii)(128));
	printf("%d ", F(isascii)(-1));
	printf("\n");
}

void	test_isprint()
{
	printf("\nisprint\n");
	printf("%d ", F(isprint)(' '));
	printf("%d ", F(isprint)('7'));
	printf("%d ", F(isprint)('a'));
	printf("%d ", F(isprint)('Z'));
	printf("%d ", F(isprint)('\n'));
	printf("%d ", F(isprint)('\t'));
	printf("%d ", F(isprint)('\0'));
}

void	test_strlen()
{
	printf("\nstrlen\n");
	char str[] = "abcd";
	printf("%lu\n", F(strlen)(str));
}

void	test_memset()
{
	printf("\nmemset\n");
	char	str[] = "abcdefg12345";
	printf("%c\n", *(char *)F(memset)(str, 65, 5));
	printf("%s\n", str);
}

void	test_bzero()
{
	printf("\nbzero\n");
	char str[] = "12345678";
	F(bzero)(str, 4);
	for (size_t i = 0; i < 5; i++)
	{
		if (str[i] == '\0')
			printf("\\0");
		else
			printf("%c", str[i]);
	}
	printf("\n");
}

void	test_memcpy()
{
	printf("\nmemcpy\n");
	char str[] = "1234567890";
	printf("%s\n",(char *)F(memcpy)(str, &str[5], 3));
}

void	test_memmove()
{
	//dstとsrcがかぶっていてもちゃんと移動しているように見える　memcpyより有能
	//dstが足りない場合はエラー処理だが、srcが足りない場合は未定義動作
	printf("\nmemmove\n");
	char str[] = "1234567890";
	printf("%s\n", (char *)F(memmove)(str, &str[2], 5));
}

void	test_memchr()
{
	//destの長さは考えていない　nの分だけ探す
	printf("\nmemchr\n");
	char str[] = "1234567890";
	char *result = (char *)F(memchr)(str, 'a', 10);
	printf("%s\n", result);
	result = (char *)F(memchr)(str, '3', 10);
	printf("%s\n", result);
}

void	test_memcmp()
{
	printf("\nmemcmp\n");
	char s1[] = "12345";
	char s2[] = "12356";
	printf("%d\n", F(memcmp)(s1, s2, 3));
	printf("%d\n", F(memcmp)(s1, s2, 4));
	printf("%d\n", F(memcmp)(s1, s2, 5));
}

void	test_strnstr()
{
	// haystackにnull文字が来たらそこで打ち切る
	// haystackのlen文字目以降は見ない
	printf("\nstrnstr\n");
	char s1[] = "abcdefghij";
	char s2[] = "gh";
	printf("%s\n", F(strnstr)(s1, s2, 6));
	printf("%s\n", F(strnstr)(s1, s2, 7));
	printf("%s\n", F(strnstr)(s1, s2, 8));
	printf("%s\n", F(strnstr)(s1, s2, 9));
}

void	test_strlcpy()
{
	printf("\nstrlcpy\n");
	char s1[] = "Hello World!";
	char s2[5];
	printf("%lu\n", F(strlcpy)(s2, s1, 2));
	printf("%s\n", s2);
	char s3[5];
	printf("%lu\n", F(strlcpy)(s3, s1, 5));
	printf("%s\n", s3);
	char s4[5];
	printf("%lu\n", F(strlcpy)(s4, s1, 0));
}

void	test_strlcat()
{
	printf("\nstrlcat\n");
	char s1[25];
	F(strlcpy)(s1, "Hello ", 25);
	char s2[] = "World!";
	printf("%lu\n", F(strlcat)(s1, s2, 3));
	printf("%s\n", s1);
	printf("%lu\n", F(strlcat)(s1, s2, 11));
	printf("%s\n", s1);
	printf("%lu\n", F(strlcat)(s1, s2, 25));
	printf("%s\n", s1);
}

void	test_toupper()
{
	printf("\ntoupper\n");
	printf("%c\n", F(toupper)('a'));
	printf("%c\n", F(toupper)('A'));
	printf("%c\n", F(toupper)('k'));
	printf("%c\n", F(toupper)('1'));
	printf("%c\n", F(toupper)('\t'));
	printf("%c\n", F(toupper)('z'));
}

void	test_tolower()
{
	printf("\ntolower\n");
	printf("%c\n", F(tolower)('a'));
	printf("%c\n", F(tolower)('A'));
	printf("%c\n", F(tolower)('K'));
	printf("%c\n", F(tolower)('1'));
	printf("%c\n", F(tolower)('\t'));
	printf("%c\n", F(tolower)('Z'));
}

void	test_strchr()
{
	printf("\nstrchr\n");
	char str[] = "Hello world!";
	printf("%s\n", F(strchr)(str, 'e'));
	printf("%s\n", F(strchr)(str, ' '));
	printf("%s\n", F(strchr)(str, 'l'));
	printf("%s\n", F(strchr)(str, '\0'));
}

void	test_strrchr()
{
	printf("\nstrrchr\n");
	char str[] = "Hello world!";
	printf("%s\n", F(strrchr)(str, 'e'));
	printf("%s\n", F(strrchr)(str, ' '));
	printf("%s\n", F(strrchr)(str, 'l'));
	printf("%s\n", F(strrchr)(str, 'o'));
	printf("%s\n", F(strrchr)(str, '\0'));
}

void	test_strncmp()
{
	printf("\nstrncmp\n");
	char s1[] = "Hello";
	char s2[] = "hello";
	char s3[] = "Hella";
	char s4[] = "Hello!";
	printf("%d ", F(strncmp)(s1, s1, 5));
	printf("%d ", F(strncmp)(s1, s2, 5));
	printf("%d ", F(strncmp)(s1, s3, 5));
	printf("%d ", F(strncmp)(s1, s3, 3));
	printf("%d ", F(strncmp)(s1, s4, 6));
	printf("\n");
}

void	test_atoi()
{
	printf("\natoi\n");
	printf("%d\n", F(atoi)("0"));
	printf("%d\n", F(atoi)(" 	123"));
	printf("%d\n", F(atoi)("  	+123"));
	printf("%d\n", F(atoi)("  	++123"));
	printf("%d\n", F(atoi)("  	-123"));
	printf("%d\n", F(atoi)("  	--123"));
	printf("%d\n", F(atoi)("  	2147483647"));
	printf("%d\n", F(atoi)("  	2147483648"));
	printf("%d\n", F(atoi)("  	-2147483648"));
	printf("%d\n", F(atoi)(""));
	printf("%d\n", F(atoi)("  "));
}

int	main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_atoi();
	return (0);
}
