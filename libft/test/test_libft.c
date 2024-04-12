#include <stdio.h>
#include <string.h>
#include "libft.h"

#ifdef FT
#define FUNCTION(name) ft_ ## name
#else
#define FUNCTION(name) name
#endif

//　このdefineを関数の数だけ書く必要がある
#define STRLEN(...) FUNCTION(strlen)(__VA_ARGS__)


int	main(void)
{
	printf("strlen\n");
	char *str = "abcde";
	printf("%lu\n", STRLEN(str));
	return (0);
}
