/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:39:34 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/18 21:04:06 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1とs2を繋いだ文字列を返す
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcpy(&result[len1], s2, len2 + 1);
	return (result);
}
