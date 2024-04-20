#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

#ifdef FT
# define F(name) ft_ ## name
#else
# define F(name) name
#endif

//part1

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
	printf("\nmemmove\n");
	char str[] = "1234567890";
	printf("%s\n", (char *)F(memmove)(str, &str[2], 5));
}

void	test_memchr()
{
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

void	test_calloc()
{
	printf("\ncalloc\n");
	char *s = (char *)F(calloc)(10, 1);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", s[i]);
	}
	printf("\n");
	free(s);
}

void	test_strdup()
{
	printf("\nstrdup\n");
	char *s1 = "Hello world";
	char *s2 = F(strdup)(s1);
	printf("%s\n", s2);
	free(s2);
}

//part2
void	test_substr()
{
	printf("\nsubstr\n");
	char *str = "Hello world";
	char *s1 = ft_substr(str, 0, 5);
	printf("result %s\nanswer Hell\n", s1);
	free(s1);
	char *s2 = ft_substr(str, 1, 7);
	printf("result %s\nanswer ello w\n", s2);
	free(s2);
	char *s3 = ft_substr(str, 2, 20);
	printf("result %s\nanswer llo world\n", s3);
	free(s3);
}

void	test_strjoin()
{
	printf("\nstrjoin\n");
	char *s1 = "Hello ";
	char *s2 = "World";
	char *str1 = ft_strjoin(s1, s2);
	char *str2 = ft_strjoin(s1, s1);
	char *str3 = ft_strjoin(s2, s2);
	printf("result %s\nanswer Hello World\n", str1);
	printf("result %s\nanswer Hello Hello \n", str2);
	printf("result %s\nanswer WorldWorld\n", str3);
	free(str1);
	free(str2);
	free(str3);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q libft");
}

void	ft_add(void *data)
{
	*(int *)data = *(int *)data + 1;
}

int	main(void)
{
	// //part1
	// test_isalpha();
	// test_isdigit();
	// test_isalnum();
	// test_isascii();
	// test_isprint();
	// test_strlen();
	// test_memset();
	// test_bzero();
	// test_memcpy();
	// test_memmove();
	// test_memchr();
	// test_memcmp();
	// test_strnstr();
	// test_strlcpy();
	// test_strlcat();
	// test_toupper();
	// test_tolower();
	// test_strchr();
	// test_strrchr();
	// test_strncmp();
	// test_atoi();
	// test_calloc();
	// test_strdup();
	// //part2
	// test_substr();
	// test_strjoin();

	return (0);
}
