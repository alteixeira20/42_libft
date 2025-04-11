/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:44:34 by paalexan          #+#    #+#             */
/*   Updated: 2025/04/11 00:48:34 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_append_char(char *str, char c)
{
	char	*new;
	size_t	len;

	if (!str)
		len = 0;
	else
		len = ft_strlen(str);
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	if (str)
	{
		ft_memcpy(new, str, len);
		free(str);
	}
	new[len] = c;
	new[len + 1] = '\0';
	return (new);
}
