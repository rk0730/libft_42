#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}
