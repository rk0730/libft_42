#include <stdio.h>
#include "srcs/libft.h"

int	main(void)
{
	char *str = "abc123";
	printf("len %d\n", ft_strlen(str));
	while (*str)
	{
		printf("%d\n", ft_isdigit(*str));
		str++;
	}
	return (0);
}
