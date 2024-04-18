/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:30:56 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/18 19:33:14 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// sの長さは考えていない　nの分だけ探す
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
