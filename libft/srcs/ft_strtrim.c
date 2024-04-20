/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:52 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/20 17:06:44 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1の始めと終わりからsetに含まれる文字を除いて返す
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) != NULL)
	{
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) != NULL && end > 0)
	{
		end--;;
	}
	result = ft_substr(s1, start, end - start + 1);
	if (!result)
		return (NULL);
	return (result);
}
