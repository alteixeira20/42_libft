/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:38:59 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 13:36:07 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	signal;
	int	i;

	i = 0;
	result = 0;
	signal = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
			return (0);
		else if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return ((int)result * signal);
}
