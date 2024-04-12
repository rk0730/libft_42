#include <stdio.h>
#include <string.h>
#include "libft.h"

#ifdef FT
#define F(name) ft_ ## name
#else
#define F(name) name
#endif

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
	printf("\nmemmove\n");
	char str[] = "1234567890";
	char str_alpha[] = "abcdefgh";
	memmove(str, &str_alpha[4], 8);
	printf("%s\n", str);
	printf("%c\n", str[5]);
	printf("%c\n", str[6]);
	printf("%c\n", str[7]);
	printf("%c\n", str[8]);
	printf("%c\n", str[9]);
}

int	main(void)
{
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	return (0);
}
