/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:31:13 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/20 18:37:39 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dstとsrcが被っても大丈夫　dstが足りないとエラー、srcが足りないのは未定義動作
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)malloc(len);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
