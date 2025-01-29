/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:37:47 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/25 20:25:41 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <ctype.h>
#include <stdio.h>

void	test_isprint(FILE *results)
{
	int	i;
	int	test[4] = {'A', '0', 'z', '*'};

	i = 0;
	while (i < 4)
	{
		if (!(ft_isprint(test[i]) && isprint(test[i])))
		{

			fprintf(results, "ft_isprint: KO | ft_isprint(%i)", ft_isprint(test[i]));
			fprintf(results, " != isprint(%i)\n", isprint(test[i]));	
			break ;
		}
		else
			i++;
	}
	fprintf(results, "ft_isprint: SUCCESS\n");
}
