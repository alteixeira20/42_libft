/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:10:22 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 16:32:57 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return ((unsigned char *)(tmp_s + i));
		i++;
	}
	return (NULL);
}
