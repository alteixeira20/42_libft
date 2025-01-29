/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:36 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 14:12:45 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBR_TESTS 3

void	test_calloc(FILE *results)
{
	int		i;
	size_t	num_elements[NBR_TESTS] = {0, 10, 1024};  // Number of elements to allocate
	size_t	element_size[NBR_TESTS] = {1, sizeof(int), sizeof(char)};  // Size of each element
	void	*res1, *res2;

	for (i = 0; i < NBR_TESTS; i++)
	{
		// Allocate memory with ft_calloc and standard calloc
		res1 = ft_calloc(num_elements[i], element_size[i]);
		res2 = calloc(num_elements[i], element_size[i]);

		// Check for mismatch in NULL return values
		if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		{
			fprintf(results, "ft_calloc: KO - Mismatch in NULL result for calloc with elements=%zu, size=%zu\n", num_elements[i], element_size[i]);
			free(res2);
			free(res1);
			return;
		}

		// Check for mismatch in zero-initialized memory content
		if (res1 && res2 && memcmp(res1, res2, num_elements[i] * element_size[i]) != 0)
		{
			fprintf(results, "ft_calloc: KO - Non-zero content in ft_calloc for elements=%zu, size=%zu\n", num_elements[i], element_size[i]);
			free(res2);
			free(res1);
			return;
		}

		// Free memory for this test iteration
		free(res2);
		free(res1);
	}

	// If all tests passed, print the single success message
	fprintf(results, "ft_calloc: SUCCESS\n");
}
