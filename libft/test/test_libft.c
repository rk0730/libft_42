#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

#ifdef FT
#define F(name) ft_ ## name
#else
#define F(name) name
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
	printf("\nstrnstr\n");
	char s1[] = "abcdefghij";
	char s2[] = "gh";
	printf("%s\n", F(strnstr)(s1, s2, 6));
	printf("%s\n", F(strnstr)(s1, s2, 7));
	printf("%s\n", F(strnstr)(s1, s2, 8));
	printf("%s\n", F(strnstr)(s1, s2, 9));
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
	return (0);
}
