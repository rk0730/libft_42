/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:09:42 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/28 19:31:56 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
	{
		count++;
		return (count);
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	ft_itoa_help(char *result, int n, int len)
{
	if (n == 0)
	{
		result[len] = '0';
		return ;
	}
	while (n != 0)
	{
		result[len] = '0' + n % 10;
		len--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;

	i = ft_count_digits(n);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (n == -2147483648)
	{
		result[0] = '-';
		result[i - 1] = '8';
		ft_itoa_help(result, 214748364, i - 2);
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	ft_itoa_help(result, n, i - 1);
	return (result);
}
