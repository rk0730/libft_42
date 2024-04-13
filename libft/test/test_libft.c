#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

#ifdef FT
#define F(name) ft_ ## name
#else
#define F(name) name
#endif

void	test_isdigit()
{
	printf("\nisdigit\n");
	printf("%d\n", F(isdigit)('1'));
	printf("%d\n", F(isdigit)('2'));
	printf("%d\n", F(isdigit)('a'));
	printf("%d\n", F(isdigit)('\n'));

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
	test_isdigit();
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
