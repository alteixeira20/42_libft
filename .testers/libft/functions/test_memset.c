/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:27:22 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/26 17:59:35 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_memset(FILE *results)
{
	int	i;
	char	test1[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};	
	char	test2[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};
	char	c = '0';
	size_t	size = 5;

	i = 0;
	while (i < NBR_TESTS)
	{
		// Call ft_bzero and bzero to zero out the specified portion of each string
		ft_memset(test1[i], c, size);
		memset(test2[i], c, size);
		// Check if the return value of ft_memset matches the expected pointer
		if (ft_memset(test1[i], c, size) != test1[i] || 
		    memset(test2[i], c, size) != test2[i])
		{
			fprintf(results, "ft_memset: KO | Return value mismatch\n");
			return;
		}

		// Check if the contents match
		if (strcmp(test1[i], test2[i]) != 0)
		{
			fprintf(results, "ft_memset: KO | ft_memset(%s) != memset(%s)\n", test1[i], test2[i]);	
			return;
		}
		i++;
	}
	fprintf(results, "ft_memset: SUCCESS\n");
}

