/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:41:45 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/04 16:05:53 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define NBR_TESTS 18

void	test_atoi(FILE *results)
{
	int		i;
	char	*test_strings[NBR_TESTS] = {
		"42", "-42", "   123", "   -123", "--42", "++42", 
		"2147483648", "-2147483649", "abc123", "123abc", "",
		" \t\v\n\r\f123", "+0000000000000000000000000000000000000000000000000000123",
		"\t 10", "\n 11", "\v 12", "\f 13", "\r 14"};

	// Run each test case
	i = 0;
	while (i < NBR_TESTS)
	{
		int res1 = ft_atoi(test_strings[i]);
		int res2 = atoi(test_strings[i]);

		// Check if both results match
		if (res1 != res2)
		{
			fprintf(results, "ft_atoi(\"%s\"): KO | Expected: %d, Got: %d\n", 
				test_strings[i], res2, res1);
			return;
		}
		i++;
	}
	fprintf(results, "ft_atoi: SUCCESS\n");
}
