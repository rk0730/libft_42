#include <stdio.h>
#include <string.h>
#include "libft.h"

#ifdef FT
#define F(name) ft_ ## name
#else
#define F(name) name
#endif

int	main(void)
{
	printf("strlen\n");
	char *str = "abcde";
	printf("%lu\n", F(strlen)(str));
	return (0);
}
