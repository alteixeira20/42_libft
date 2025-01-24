/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:02:10 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 18:41:32 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return (tmp_s1[i] - tmp_s2[i]);
		else
			i++;
	}
	return (0);
}
