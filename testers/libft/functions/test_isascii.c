/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:37:47 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 19:53:42 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <ctype.h>
#include <stdio.h>

void	test_isascii(FILE *results)
{
	int	i;
	char	test[4] = {'\n', '\0', '*', '?'};

	i = 0;
	while (test[i])
	{
		if (ft_isascii(test[i]) != isascii(test[i]))
		{
			fprintf(results, "ft_isascii: KO | ft_isascii(%i)", ft_isascii(test[i]));
			fprintf(results, " != iascii(%i)\n", isascii(test[i]));	
			break ;
		}
		else
			i++;
	}
	fprintf(results, "ft_isascii: SUCCESS\n");
}
