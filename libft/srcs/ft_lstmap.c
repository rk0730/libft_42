/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitaoryoma <kitaoryoma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:56:44 by rkitao            #+#    #+#             */
/*   Updated: 2024/04/21 15:17:05 by kitaoryoma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	t_list	*new;

	if (!lst)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	printf("parent %p\n", &result);
	printf("first %p\n", result);
	// del(lst->content);
	printf("del done\n");
	if (!result)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		new = ft_lstnew(f(tmp->content));
		printf("%p\n", tmp);
		// del(tmp->content);
		// printf("add\n");
		if (!new)
			return (NULL);
		ft_lstadd_back(&result, new);
		tmp = tmp->next;
	}
	printf("parent %p\n", &result);
	del("!");
	// ft_lstclear(&lst, del);
	return (result);
}
