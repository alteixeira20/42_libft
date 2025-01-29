/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:08:47 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 00:51:41 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 4

void	test_strlcat(FILE *results)
{
	int		i = 0;
	char	test1[NBR_TESTS][20] = {"pqrs", "pqrs", "pqrs", "pqrs"};
	char	test2[NBR_TESTS][20] = {"pqrs", "pqrs", "pqrs", "pqrs"};
	char	*src = "abcdefghi";
	size_t	sizes[NBR_TESTS] = {10, 11, 12, 13};

	// Test ft_strlcat with different buffer sizes using a while loop
	while (i < NBR_TESTS)
	{
		// Clear destination buffers between tests
		memset(test1[i], 0, sizeof(test1[i]));
		memset(test2[i], 0, sizeof(test2[i]));
		strcpy(test1[i], "pqrs");
		strcpy(test2[i], "pqrs");

		// Perform strlcat on both test1 and test2 with the current buffer size
		size_t res1 = ft_strlcat(test1[i], src, sizes[i]);
		size_t res2 = strlcat(test2[i], src, sizes[i]);

		// Check if the return values match
		if (res1 != res2)
		{
			fprintf(results, "ft_strlcat(size=%lu): KO | Expected %lu, got %lu\n", sizes[i], res2, res1);
			return;
		}

		// Use memcmp to compare the full buffer contents for precise matching
		if (memcmp(test1[i], test2[i], sizes[i]) != 0)
		{
			fprintf(results, "ft_strlcat(size=%lu): KO | Buffer content mismatch | Expected: \"%s\" & Got: \"%s\"\n", sizes[i], test2[i], test1[i]);
			return;
		}
		
		i++;
	}

	fprintf(results, "ft_strlcat: SUCCESS\n");
}
