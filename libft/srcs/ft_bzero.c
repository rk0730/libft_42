/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:32:11 by kitaoryoma        #+#    #+#             */
/*   Updated: 2024/04/14 00:32:13 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// memsetを使う
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
