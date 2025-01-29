/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:08:04 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 18:21:35 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

#define NBR_TESTS 6

void	test_memcmp(FILE *results)
{
	size_t	i;
	size_t	n[NBR_TESTS] = {5, 9, 0, 0, 0, 5};  // Test cases for n == 0 and non-ASCII
	char	*test1[NBR_TESTS] = {"Hello world", "Test case", "Another test", "test", "", "abcdef"};
	char	*test2[NBR_TESTS] = {"Hello world", "Test Case", "Another", "", "test", "abc\375xx"};

	// Regular cases, including edge cases
	i = 0;
	while (i < NBR_TESTS)
	{
		int res1 = ft_memcmp(test1[i], test2[i], n[i]);
		int res2 = memcmp(test1[i], test2[i], n[i]);
		
		// Check if the return values match in sign and value
		if ((res1 == 0 && res2 != 0) || (res1 != 0 && res2 == 0) || (res1 > 0 && res2 <= 0) || (res1 < 0 && res2 >= 0))
		{
			fprintf(results, "ft_memcmp(%s, %s, %zu): KO | Expected sign: %d, Got sign: %d\n", 
				test1[i], test2[i], n[i], (res2 > 0) - (res2 < 0), (res1 > 0) - (res1 < 0));
			return;
		}
		i++;
	}
	fprintf(results, "ft_memcmp: SUCCESS\n");
}
