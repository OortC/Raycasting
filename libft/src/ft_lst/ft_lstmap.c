/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeblee <jaeblee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:02:06 by jaebin            #+#    #+#             */
/*   Updated: 2023/10/17 19:57:09 by jaeblee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*temp_f;
	t_list	*temp_node;
	t_list	*result;

	if (!f || !del)
		return (0);
	result = NULL;
	while (lst)
	{
		temp_f = f(lst->content);
		temp_node = ft_lstnew(temp_f);
		if (!temp_node)
		{
			del(temp_f);
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, temp_node);
		lst = lst->next;
	}
	return (result);
}
