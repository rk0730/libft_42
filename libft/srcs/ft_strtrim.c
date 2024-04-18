/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:03:52 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/18 21:17:37 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1からsetに含まれる文字を除いて返す
char	*ft_strtrim(char const *s1, char const *set)
{
	//setにあるか確認していきながら追加していく　それを最後までやる
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	
}
