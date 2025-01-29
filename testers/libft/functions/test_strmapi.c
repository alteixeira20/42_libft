/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:52:27 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 17:05:19 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Example function to use with ft_strmapi
static char example_func(unsigned int i, char c)
{
	return (c + i);  // Shift each character by its index
}

void	test_strmapi(FILE *results)
{
	const char	*test_str = "abcdef";
	const char	*expected_result = "acegik";
	char		*result;

	// Run ft_strmapi with test string and example function
	result = ft_strmapi(test_str, example_func);

	// Check if result matches the expected output
	if (result && strcmp(result, expected_result) == 0)
	{
		fprintf(results, "ft_strmapi: SUCCESS\n");
	}
	else
	{
		fprintf(results, "ft_strmapi: KO | Expected: \"%s\", Got: \"%s\"\n",
				expected_result, result ? result : "NULL");
	}

	// Free allocated memory by ft_strmapi
	free(result);
}
