/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:02:33 by 1652952399        #+#    #+#             */
/*   Updated: 2024/04/28 17:48:23 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//startは最初の0以外の数字 数字列の桁数を数え、19桁より多い場合は確定　19桁の場合はstrncmpを使ってより大きい場合を見つける
static int	ft_atoi_helper(const char *start)
{
	size_t	digit_len;

	digit_len = 0;
	while (ft_isdigit(start[digit_len]))
		digit_len++;
	if (digit_len > 19)
		return (1);
	if (digit_len == 19 && ft_strncmp(start, "9223372036854775807", 19) > 0)
		return (1);
	return (0);
}

//最初にisspace(3) 符号が最大1つ　オーバーフローする
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (ft_atoi_helper(str))
	{
		return (-1 * (sign == 1));
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
