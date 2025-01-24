/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:08:19 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 00:58:15 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;
	size_t		len_src;
	size_t		i;
	size_t		k;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	i = len_dst;
	k = 0;
	while (src[k] && (size - 1 > i))
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
