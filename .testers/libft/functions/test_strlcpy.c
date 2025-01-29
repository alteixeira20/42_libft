/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:05:19 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/27 23:33:04 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_strlcpy(FILE *results)
{
	int		i;
	char	test1[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};	
	char	test2[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};
	char	*str = "00000000";
	size_t	size = 5;

	// Case when size == 0
	size_t	res1 = ft_strlcpy(test1[0], str, 0);
	size_t	res2 = strlcpy(test2[0], str, 0);
	
	if (res1 != res2 || strcmp(test1[0], test2[0]) != 0)
	{
		fprintf(results, "ft_strlcpy(%s): KO | strlcpy(%s) | strcmp != 0 when size(0)\n", test1[0], test2[0]);
		return;
	}

	// Regular cases
	i = 0;
	while (i < NBR_TESTS)
	{
		res1 = ft_strlcpy(test1[i], str, size);
		res2 = strlcpy(test2[i], str, size);
		
		// Check if the return values match
		if (res1 != res2)
		{
			fprintf(results, "ft_strlcpy(%li): KO | strlcpy(%li) | Return value mismatch\n", res1, res2);
			return;
		}

		// Check if the contents match
		if (strcmp(test1[i], test2[i]) != 0)
		{
			fprintf(results, "ft_strlcpy: KO | ft_strlcpy(%s) != strlcpy(%s)\n", test1[i], test2[i]);	
			return;
		}
		i++;
	}
	fprintf(results, "ft_strlcpy: SUCCESS\n");
}

