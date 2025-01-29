/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:28:25 by paalexan          #+#    #+#             */
/*   Updated: 2025/01/29 23:32:32 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *lst)
{
	void	*temp;

	if (!lst || !lst->next)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
}
