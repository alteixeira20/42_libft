/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:43:05 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 19:47:23 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst)
	{
		*lst = new;
		return ;
	}
	node = ft_lstlast(*lst);
	if (!node)
		*lst = new;
	else
		node->next = new;
}
