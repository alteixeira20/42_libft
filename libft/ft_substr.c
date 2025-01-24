/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:50:24 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 16:29:43 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;
	size_t			len_substr;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len_substr = ft_strlen(s + start);
	if (len_substr < len)
		len = len_substr;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
