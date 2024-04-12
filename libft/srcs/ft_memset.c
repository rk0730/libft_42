#include "libft.h"

// bをそのまま返す　b, cをunsigned intにキャストして考える
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	src;
	unsigned char	*dest;
	size_t			i;

	src = (unsigned char)c;
	dest = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*dest = src;
		dest++;
		i++;
	}
	return (b);
}
