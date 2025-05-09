/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:30:49 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/05/04 14:37:17 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//メモリをsize[bite]*count[要素]分確保し、中身をすべて0で初期化して先頭アドレスを返す
void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	if (size != 0 && SIZE_MAX / size < count)
	{
		return (NULL);
	}
	result = malloc(count * size);
	if (!result)
	{
		return (NULL);
	}
	ft_bzero(result, count * size);
	return (result);
}
