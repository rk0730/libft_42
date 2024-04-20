/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:08:35 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/20 17:31:11 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//startのindexから始まり、ヌル文字を除いてlen文字コピーされた文字列を作る　lenが多い場合は最後の文字までだけコピー
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			max;
	unsigned int	i;
	char			*result;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		ft_putstr("ft_substr: start >= ft_strlen(s)\n");
		result = ft_calloc(1, 1);
		return (result);
	}
	i = start;
	max = 0;
	while (s[i])
	{
		i++;
		max++;
	}
	if (max < len)
		len = max;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}
