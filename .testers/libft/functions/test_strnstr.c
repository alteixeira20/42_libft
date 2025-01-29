/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:36:53 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 19:38:24 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <bsd/string.h>
#include <stdio.h>

#define NBR_TESTS 5

void	test_strnstr(FILE *results)
{
	int		i;
	char	*big[NBR_TESTS] = {"Hello world", "This is a test string", "Another example", "Find me here", "Short"};
	char	*little[NBR_TESTS] = {"world", "test", "example", "me", "not found"};
	size_t	len[NBR_TESTS] = {11, 14, 7, 10, 8};

	// Testing each case
	i = 0;
	while (i < NBR_TESTS)
	{
		char *res1 = ft_strnstr(big[i], little[i], len[i]);
		char *res2 = strnstr(big[i], little[i], len[i]);

		// Check if both results are NULL or if both point to the same substring
		if (res1 != res2)
		{
			fprintf(results, "ft_strnstr(\"%s\", \"%s\", %zu): KO | Expected: %p, Got: %p\n", 
				big[i], little[i], len[i], res2, res1);
			return;
		}
		i++;
	}
	fprintf(results, "ft_strnstr: SUCCESS\n");
}
