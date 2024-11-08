/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:19 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/14 12:55:20 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lst_e;

	if (!lst)
		return (NULL);
	lst2 = 0;
	while (lst)
	{
		lst_e = ft_lstnew(f(lst->content));
		if (!lst_e)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, lst_e);
		lst = lst->next;
	}
	return (lst2);
}
