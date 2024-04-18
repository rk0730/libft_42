/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:26:57 by 1652952399        #+#    #+#             */
/*   Updated: 2024/04/18 19:36:52 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dstをオーバーフローしないようにコピーしていく
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i < dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
