/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:52 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/20 15:37:48 by rkitao           ###   ########.fr       */
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
	ft_strlcpy(result, str, len + 1);
	
}

//s1からsetに含まれる文字を除いて返す
char	*ft_strtrim(char const *s1, char const *set)
{
	//setにあるか確認していきながら追加していく　それを最後までやる
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	
}
