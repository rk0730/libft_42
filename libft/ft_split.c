/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:08:59 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/20 20:02:18 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//エラーがあったらresult_pをNULLにする
void	ft_spli_help(char ***result_p, char *s, size_t *start_p, size_t *end_p)
{
	char	*tmp;

	if (*end_p > *start_p)
	{
		tmp = ft_substr(s, *start_p, *end_p - *start_p);
		if (!tmp)
		{
			*result_p = NULL;
			return ;
		}
		*result_p = ft_array_add(*result_p, tmp);
	}
	*start_p = *end_p;
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	end;
	char	**result;

	result = (char **)malloc(sizeof(char *));
	if (!s || !result)
		return (NULL);
	*result = NULL;
	start = 0;
	while (s[start])
	{
		while (s[start] && s[start] == c)
			start = start + 1;
		end = start;
		while (s[end] && s[end] != c)
			end = end + 1;
		ft_spli_help(&result, (char *)s, &start, &end);
		if (!result)
			return (NULL);
	}
	return (result);
}
