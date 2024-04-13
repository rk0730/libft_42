#include "libft.h"

// destの長さは考えていない　nの分だけ探す
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	find;
	unsigned char	*dest;
	size_t			i;

	find = (unsigned char)c;
	dest = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (dest[i] == find)
			return (&dest[i]);
		i++;
	}
	return (NULL);
}
