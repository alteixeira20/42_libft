/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:11 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/06 11:03:37 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define NBR_TESTS 10

void	test_itoa(FILE *results)
{
	int		i;
	int		test_numbers[NBR_TESTS] = {42, -42, 0, INT_MAX, INT_MIN, 12345, -12345, 1, -1, 100000};
	char	*expected_results[NBR_TESTS] = {"42", "-42", "0", "2147483647", "-2147483648", "12345", "-12345", "1", "-1", "100000"};

	// Run each test case
	i = 0;
	while (i < NBR_TESTS)
	{
		char *result = ft_itoa(test_numbers[i]);

		// Check if the result matches the expected string
		if (strcmp(result, expected_results[i]) != 0)
		{
			fprintf(results, "ft_itoa(%d): KO | Expected: \"%s\", Got: \"%s\"\n", 
				test_numbers[i], expected_results[i], result);
			free(result);
			return;
		}
		free(result);
		i++;
	}
	fprintf(results, "ft_itoa: SUCCESS\n");
}
