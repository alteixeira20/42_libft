/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:28:02 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/26 17:59:05 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <strings.h>
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_bzero(FILE *results)
{
	int	i;
	char	test1[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};	
	char	test2[NBR_TESTS][20] = {"aqui a gato", "hello 42", ""};
	size_t	size = 5;

	i = 0;
	while (i < NBR_TESTS)
	{
		// Call ft_bzero and bzero to zero out the specified portion of each string
		ft_bzero(test1[i], size);
		bzero(test2[i], size);

		// Check if the contents match
		if (strcmp(test1[i], test2[i]) != 0)
		{
			fprintf(results, "ft_bzero: KO | ft_bzero(%s) != bzero(%s)\n", test1[i], test2[i]);	
			return;
		}
		i++;
	}
	fprintf(results, "ft_bzero: SUCCESS\n");
}

