/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:08:03 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 20:53:45 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned int	i;
	unsigned int	k;

	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		dest[i + k] = s2[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
