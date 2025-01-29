/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:47:56 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 16:34:09 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>  // for SIZE_MAX
#include <malloc.h>

#define NBR_TESTS 6
#define MIN(a, b) ((a) < (b) ? (a) : (b))  // Macro to get the minimum of two values

void	test_substr(FILE *results)
{
	// Test cases, including cases with large len and boundary conditions
	char	*test_strings[NBR_TESTS] = {"Hello World", "42 Network", "hola", "Libft project", "hola", "hola"};
	unsigned int start_indices[NBR_TESTS] = {0, 3, 0, 2, 0, 2};
	size_t lengths[NBR_TESTS] = {5, 4, SIZE_MAX, 30, 5, 3};
	char	*expected_results[NBR_TESTS] = {"Hello", "Netw", "hola", "bft project", "hola", "la"};
	char	*res;
	int		i = 0;

	while (i < NBR_TESTS)
	{
		// Run ft_substr and get the result
		res = ft_substr(test_strings[i], start_indices[i], lengths[i]);

		// Calculate expected size based on content length with null terminator
		size_t remaining_len = (start_indices[i] < strlen(test_strings[i])) ? strlen(test_strings[i]) - start_indices[i] : 0;
		size_t expected_size = MIN(remaining_len, lengths[i]) + 1;  // Expected size including null terminator
		size_t actual_size = res ? strlen(res) + 1 : 0;  // Length of actual content including null terminator

		// Check if result matches the expected outcome and size
		if ((res == NULL && expected_results[i] != NULL) || 
			(res != NULL && strcmp(res, expected_results[i]) != 0) ||
			actual_size != expected_size)
		{
			fprintf(results, "ft_substr: KO (Mismatch on test %d)\n", i + 1);
			fprintf(results, "Input: \"%s\", start=%u, len=%zu\n", test_strings[i] ? test_strings[i] : "NULL", start_indices[i], lengths[i]);
			fprintf(results, "Expected: \"%s\" (%zu bytes), Got: \"%s\" (%zu bytes)\n", 
					expected_results[i] ? expected_results[i] : "NULL", expected_size, res ? res : "NULL", actual_size);
			free(res);
			return;
		}

		// Free allocated memory and proceed to the next test
		free(res);
		i++;
	}

	// If all tests pass
	fprintf(results, "ft_substr: SUCCESS\n");
}
