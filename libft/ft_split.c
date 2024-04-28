/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:08:59 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/28 17:49:06 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//tmpより１つ大きいサイズ分mallocしてtmpをコピー　最後にstrをつけてtmpをfree
static char	**ft_array_add(char **tmp, char *str)
{
	int		i;
	int		tmp_len;
	char	**result;

	i = 0;
	tmp_len = 0;
	while (tmp[tmp_len])
		tmp_len++;
	result = (char **)malloc(sizeof(char *) * (tmp_len + 2));
	if (!result)
		return (NULL);
	while (i < tmp_len)
	{
		result[i] = tmp[i];
		i++;
	}
	result[tmp_len] = str;
	result[tmp_len + 1] = NULL;
	free(tmp);
	return (result);
}

//エラーがあったらresult_pをNULLにする
static void	ft_spli_help(char ***result_p, char *s, size_t *start_p, size_t *end_p)
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
