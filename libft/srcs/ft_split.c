/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkitao <rkitao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:08:59 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/20 17:39:02 by rkitao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tmpより１つ大きいサイズ分mallocしてtmpをコピー　最後にstrをつけてtmpをfree
char	**ft_arrayadd(char **tmp, char *str)
{
	int	i;
	int	tmp_len;
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


char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	end;
	char	**result;
	char	*tmp;

	result = ()
	start = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c)
			end++;
		tmp = ft_substr(s, start, end - start);
		if tmp NULL
		ft_arrayadd(result, )
	}
}

//メモ
//change index、0:to next charsetまで　1: to next !charset
int	to_next_char(char *str, char *charset, int index, int flag)
{
	int	j;
	int	set_found;

	j = 0;
	while (str[index])
	{
		set_found = 0;
		j = 0;
		while (charset[j])
		{
			if (str[index] == charset[j])
				set_found = 1;
			j++;
		}
		if (set_found == flag)
			index++;
		else
			return (index);
	}
	return (index);
}

void	put_strarray(char *str, char *charset, char **str_array, int str_count)
{
	int	str_i;
	int	id;
	int	sub_id;
	int	i;

	str_i = 0;
	id = 0;
	while (str_i < str_count)
	{
		id = to_next_char(str, charset, id, 1);
		sub_id = to_next_char(str, charset, id, 0);
		if (sub_id - id > 0)
			str_array[str_i] = (char *)malloc(sizeof(char) * (sub_id - id + 1));
		i = 0;
		while (id < sub_id)
		{
			str_array[str_i][i] = str[id];
			id++;
			i++;
		}
		str_array[str_i][i] = '\0';
		str_i++;
	}
	str_array[str_count] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		str_count;
	int		id;
	int		sub_id;
	char	**str_array;

	str_count = 0;
	id = 0;
	while (str[id])
	{
		id = to_next_char(str, charset, id, 1);
		sub_id = to_next_char(str, charset, id, 0);
		if (sub_id > id)
			str_count++;
		id = sub_id;
	}
	str_array = (char **)malloc(sizeof(char *) * (str_count + 1));
	put_strarray(str, charset, str_array, str_count);
	return (str_array);
}
