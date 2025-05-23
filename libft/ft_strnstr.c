/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:31:26 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/28 16:58:19 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//haystackからneedleを検索する　haystackのlen文字目以降は見ない
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!haystack && len == 0)
		return (NULL);
	if (*haystack)
		i = 0;
	i = 0;
	needle_len = ft_strlen((char *)needle);
	if (needle_len == 0 && ft_memcmp(&haystack[i], needle, needle_len) == 0)
		return ((char *)&haystack[i]);
	while (i + needle_len <= len && haystack[i])
	{
		if (ft_memcmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
