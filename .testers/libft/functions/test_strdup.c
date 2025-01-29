/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:36:42 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/04 16:53:45 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NBR_TESTS 5

void	test_strdup(FILE *results)
{
	int		i;
	char	*test_strings[NBR_TESTS] = {"", "sadfvbf", "fdfjkdf\n35346", "Hello world", "Test strdup"};
	
	i = 0;
	while (i < NBR_TESTS)
	{
		char *res1 = ft_strdup(test_strings[i]);
		char *res2 = strdup(test_strings[i]);
		size_t expected_size = strlen(test_strings[i]) + 1;
		size_t allocated_size = (res1) ? expected_size : 0;  // Assume ft_strdup allocated expected_size if res1 is not NULL

		// Check if both results match
		if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL) || strcmp(res1, res2) != 0)
		{
			fprintf(results, "ft_strdup: KO (see results.txt for additional details)\n");
			fprintf(results, "Error in test %d: ft_strdup(\"%s\")\n", i + 1, test_strings[i]);
			fprintf(results, "Expected: \"%s\", Got: \"%s\"\n", res2 ? res2 : "NULL", res1 ? res1 : "NULL");

			// Print expected and allocated bytes information
			fprintf(results, "Error in test %d: ft_strdup(\"%s\"): expected %zu bytes, allocated %zu bytes\n", 
					i + 1, test_strings[i], expected_size, allocated_size);

			// Print memory leak information if applicable
			if (res1)
			{
				fprintf(results, "Memory leak: %p - %zu bytes\n", (void *)res1, allocated_size);
				fprintf(results, "You failed to free the memory allocated at: %p\n", (void *)res1);
			}

			free(res1);
			free(res2);
			return;
		}
		free(res1);
		free(res2);
		i++;
	}
	fprintf(results, "ft_strdup: SUCCESS\n");
}
