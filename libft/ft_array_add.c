/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:01:58 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/20 20:02:09 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//tmpより１つ大きいサイズ分mallocしてtmpをコピー　最後にstrをつけてtmpをfree
char	**ft_array_add(char **tmp, char *str)
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
