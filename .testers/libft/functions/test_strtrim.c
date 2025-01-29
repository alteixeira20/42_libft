/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:35:28 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 21:38:16 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tester.h"

#define NBR_TESTS 5

void test_strtrim(FILE *results) 
{
    // Define test cases
    char *test_strings[NBR_TESTS] = {
        "   Hello World   ",       // Leading and trailing spaces
        "xx42 Networkxx",          // Leading and trailing 'x'
        "!!Important!!",           // Leading and trailing '!'
        "NoTrimmingNeeded",        // No characters in set
        ""                         // Empty string
    };
    char *test_sets[NBR_TESTS] = {
        " ",                       // Trim spaces
        "x",                       // Trim 'x'
        "!",                       // Trim '!'
        "abc",                     // Set with no matching chars
        " "                        // Trim spaces from an empty string
    };
    char *expected_results[NBR_TESTS] = {
        "Hello World",             // Trimmed spaces
        "42 Network",              // Trimmed 'x'
        "Important",               // Trimmed '!'
        "NoTrimmingNeeded",        // No trimming
        ""                         // Empty string remains empty
    };

    int i = 0;
    while (i < NBR_TESTS) 
    {
        char *res = ft_strtrim(test_strings[i], test_sets[i]);

        // Check for allocation failure
        if (res == NULL) 
        {
            fprintf(results, "ft_strtrim: KO (Allocation failed on test %d)\n", i + 1);
            fprintf(results, "Input: s1=\"%s\", set=\"%s\"\n", test_strings[i], test_sets[i]);
            return;
        }

        // Compare result with expected output
        if (strcmp(res, expected_results[i]) != 0) 
        {
            fprintf(results, "ft_strtrim: KO (Mismatch on test %d)\n", i + 1);
            fprintf(results, "Input: s1=\"%s\", set=\"%s\"\n", test_strings[i], test_sets[i]);
            fprintf(results, "Expected: \"%s\", Got: \"%s\"\n", expected_results[i], res);
            free(res);
            return;
        }

        // Free allocated memory and continue
        free(res);
        i++;
    }

    // All tests passed
    fprintf(results, "ft_strtrim: SUCCESS\n");
}
