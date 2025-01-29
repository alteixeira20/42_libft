/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:49:17 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/26 19:02:20 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <ctype.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_toupper(FILE *results)
{
	int	i;
	char	tests[NBR_TESTS + 1] = {'A', 'b', '0'};	

	i = 0;
	while (i < NBR_TESTS)
	{
		if (ft_toupper(tests[i]) != toupper(tests[i]))
		{
			fprintf(results, "ft_toupper: KO | ft_toupper(%c) != toupper(%c)\n", ft_toupper(tests[i]), toupper(tests[i]));	
			return;
		}
		i++;
	}
	fprintf(results, "ft_toupper: SUCCESS\n");
}

