/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:09:42 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/20 20:15:37 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		sign;
	char	*result;

	sign = (n >= 0);
	result = ft_calloc(1, sizeof(char));
	if (n == -2147483648)
	{
		result = ft_stradd_first(result, '8');
		n = -214748364;
	}
	if (n < 0)
		n *= -1;
	result = ft_stradd_first(result, n % 10 + '0');
	n /= 10;
	while (n > 0)
	{
		result = ft_stradd_first(result, n % 10 + '0');
		n /= 10;
	}
	if (!sign)
		result = ft_stradd_first(result, '-');
	if (!result)
		return (NULL);
	return (result);
}
