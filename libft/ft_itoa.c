/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:01:44 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 11:06:21 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*dest;

	len = ft_num_len(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	while (len > 0)
	{
		dest[--len] = '0' + (n % 10) * sign;
		n /= 10;
	}
	if (sign == -1)
		dest[0] = '-';
	return (dest);
}
