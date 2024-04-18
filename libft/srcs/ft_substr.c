/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:08:35 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/18 20:33:03 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//startのindexから始まり、len分コピーされた文字列を作る　lenが多い場合は最後の文字までだけコピー
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				max;
	unsigned int	i;
	char			*result;

	i = start;
	max = 0;
	while (s[i])
	{
		i++;
		max++;
	}
	if ((size_t)(max + 1) < len)
		len = (size_t)(max + 1);
	result = (char *)malloc(sizeof(char) * len);
	ft_strlcpy(result, &s[start], len);
	return (result);
}
