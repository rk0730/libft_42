#include "libft.h"

// nがなくなるまでひたすらコピーしていく
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*c_dst = *c_src;
		i++;
		c_dst++;
		c_src++;
	}
	return (dst);
}
