/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:46:08 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/14 12:59:32 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = *lst;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}
