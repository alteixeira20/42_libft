/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:35:13 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 15:44:01 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_strchr(FILE *results)
{
	int		i;
	char	*test_strings[NBR_TESTS] = {"aqui a gato", "hello 42", ""};	
	char	test_chars[NBR_TESTS] = {'a', '\0', 'x'};

	// Testing each case
	i = 0;
	while (i < NBR_TESTS)
	{
		// Apply ft_strchr and strchr on each test string and character
		char *res1 = ft_strchr(test_strings[i], test_chars[i]);
		char *res2 = strchr(test_strings[i], test_chars[i]);

		// Check if both return NULL (if character is not found) or if pointers match
		if (!((res1 == NULL && res2 == NULL) || res1 == res2))
		{
			fprintf(results, "ft_strchr(\"%s\", '%c'): KO | Expected %p, got %p\n", test_strings[i], test_chars[i], res2, res1);
			return;
		}
		i++;
	}
	fprintf(results, "ft_strchr: SUCCESS\n");
}
