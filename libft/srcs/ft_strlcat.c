/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 1652952399 <1652952399@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:05:34 by 1652952399        #+#    #+#             */
/*   Updated: 2024/04/18 12:17:39 by 1652952399       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen((const char *)dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (i < dstsize - d_len - 1 && src[i] != '\0')
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[i + d_len] = '\0';
	return (d_len + s_len);
}
