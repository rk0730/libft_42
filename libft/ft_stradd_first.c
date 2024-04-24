/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:00:36 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/20 20:15:06 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//strの1文字目をcにしてstrはずらしたものを返す　strはfreeする
char	*ft_stradd_first(char *str, char c)
{
	size_t	len;
	char	*result;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	result = ft_calloc(len + 2, sizeof(char));
	if (!result)
		return (NULL);
	result[0] = c;
	ft_strlcpy(&result[1], str, len + 1);
	free(str);
	return (result);
}
