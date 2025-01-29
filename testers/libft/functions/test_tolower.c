/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:49:17 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 20:28:43 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <ctype.h>
//#include <stdio.h>

#define NBR_TESTS 3

void	test_tolower(FILE *results)
{
	int	i;
	char	tests[NBR_TESTS + 1] = {'A', 'b', '0'};	

	i = 0;
	while (i < NBR_TESTS)
	{
		if (ft_tolower(tests[i]) != tolower(tests[i]))
		{
			fprintf(results, "ft_tolower: KO | ft_tolower(%c) != tolower(%c)\n", ft_tolower(tests[i]), tolower(tests[i]));	
			return;
		}
		i++;
	}
	fprintf(results, "ft_tolower: SUCCESS\n");
}
