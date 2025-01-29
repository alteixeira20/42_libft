/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:51 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 15:45:25 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 3

void	test_strrchr(FILE *results)
{
	int		i;
	char	*test_strings[NBR_TESTS] = {"aqui a gato", "hello 42", ""};	
	char	test_chars[NBR_TESTS] = {'a', '\0', 'x'};

	// Testing each case
	i = 0;
	while (i < NBR_TESTS)
	{
		// Apply ft_strrchr and strrchr on each test string and character
		char *res1 = ft_strrchr(test_strings[i], test_chars[i]);
		char *res2 = strrchr(test_strings[i], test_chars[i]);

		// Check if both return NULL (if character is not found) or if pointers match
		if (!((res1 == NULL && res2 == NULL) || res1 == res2))
		{
			fprintf(results, "ft_strrchr(\"%s\", '%c'): KO | Expected %p, got %p\n", test_strings[i], test_chars[i], res2, res1);
			return;
		}
		i++;
	}
	fprintf(results, "ft_strrchr: SUCCESS\n");
}
