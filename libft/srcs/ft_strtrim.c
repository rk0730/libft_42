/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:52 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/20 16:34:55 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//strはmallocされたもの strの末尾にcをつけたものを返し、strはfreeする
char	*ft_stradd(char *str, char c)
{
	size_t	len;
	char	*result;

	len = ft_strlen(str);
	result = ft_calloc(len + 2, 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, len + 1);
	result[len] = c;
	free(str);
	return (result);
}

int	ft_strtrim_helper()

//s1からsetに含まれる文字を除いて返す
char	*ft_strtrim(char const *s1, char const *set)
{
	//setにあるか確認していきながら追加していく　それを最後までやる
	char	*result;
	int		flag;
	size_t	i;
	size_t	start;
	size_t	end;

	flag = 0;
	i = 0;
	start = 0;
	//startとendを置き、それぞれ端から確認していく　最後に必要分callocしてstrlcpy
	while (ft_strchr(set, s1[start]) != NULL)
	{
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) != NULL)
	{
		end--;;
	}

	
	// while (*s1)
	// {
	// 	flag = 0;
	// 	while (set[i])
	// 	{
	// 		if (*s1 == set[i])
	// 			flag = 1;
	// 		i++;
	// 	}
	// 	if (flag == 0)
	// 	result = ft_stradd(result, *s1);
	// 	if (!result)
	// 		return (NULL);
	// 	s1++;
	// }
	
	return (result);
}
