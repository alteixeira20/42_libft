/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:15 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 16:02:40 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			tmp = ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == '\0')
		tmp = ((char *)(s + i));
	return (tmp);
}
