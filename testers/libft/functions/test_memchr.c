/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:18:02 by paalexan          #+#    #+#             */
/*   Updated: 2024/10/28 16:27:25 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <string.h>
#include <stdio.h>

#define NBR_TESTS 4

void	test_memchr(FILE *results)
{
	int		i;
	char	*test_strings[NBR_TESTS] = {"aqui a gato", "hello 42", "test", 
		"\x98\x3f\x00\x19\x6d\xbf\xf1\x9a\x54\xa1\x5c\x32\x2a\x00\xf2\x11"
		"\xe0\xc8\x70\x3b\x55\x46\x44\x63\x63\x02\x2a\x17\xc8\x2e\x91\x60"
		"\x6d\x91\x7a\xda\x50\x6b\x74\xa4\x0c\xd1\xd6\x36\xd1\xc9\x47\xb1"};
	char	test_chars[NBR_TESTS] = {'a', '4', 'x', 'z'};
	size_t	test_lengths[NBR_TESTS] = {10, 6, 4, 36};  // Different lengths to test, including edge cases

	// Testing each case
	i = 0;
	while (i < NBR_TESTS)
	{
		// Apply ft_memchr and memchr on each test string, character, and length
		void *res1 = ft_memchr(test_strings[i], test_chars[i], test_lengths[i]);
		void *res2 = memchr(test_strings[i], test_chars[i], test_lengths[i]);

		// Check if both return NULL (if character is not found) or if pointers match
		if (!((res1 == NULL && res2 == NULL) || res1 == res2))
		{
			fprintf(results, "ft_memchr(%p, '%c'(%#x), %zu): KO | Expected %p, got %p\n", 
				test_strings[i], test_chars[i], test_chars[i], test_lengths[i], res2, res1);
			return;
		}
		i++;
	}
	fprintf(results, "ft_memchr: SUCCESS\n");
}
