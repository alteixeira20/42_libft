/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:26:21 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/26 19:50:12 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_memcpy(FILE *results)
{
	int	i;
	char	test1[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};	
	char	test2[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};
	char	*str = "00000000";
	size_t	size = 5;

	i = 0;
	while (i < NBR_TESTS)
	{
		ft_memcpy(test1[i], str, size);
		memcpy(test2[i], str, size);
		
		// Check if the return value of ft_memcpy matches the expected pointer
		if (ft_memcpy(test1[i], str, size) != test1[i] || 
		    memcpy(test2[i], str, size) != test2[i])
		{
			fprintf(results, "ft_memcpy: KO | Return value mismatch\n");
			return;
		}

		// Check if the contents match
		if (strcmp(test1[i], test2[i]) != 0)
		{
			fprintf(results, "ft_memcpy: KO | ft_memcpy(%s) != memcpy(%s)\n", test1[i], test2[i]);	
			return;
		}
		i++;
	}
	fprintf(results, "ft_memcpy: SUCCESS\n");
}
