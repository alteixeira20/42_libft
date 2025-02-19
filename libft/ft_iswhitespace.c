/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:03:48 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 16:10:30 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	else
		return (false);
}
