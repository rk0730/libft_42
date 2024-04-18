/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:33:16 by 1652952399        #+#    #+#             */
/*   Updated: 2024/04/18 19:35:54 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//sからcを探す　なかったらNULL
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	last;

	last = ft_strlen(s);
	i = 0;
	while (i <= last)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
