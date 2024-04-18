/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:05:34 by 1652952399        #+#    #+#             */
/*   Updated: 2024/04/18 19:36:21 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dstにsrcを繋げる　繋げた後の文字数はdstsizeを超えない
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
