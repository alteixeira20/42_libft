/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:44:01 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 23:56:17 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tester.h"

#define NBR_TESTS 6

void test_split(FILE *results)
{
    // Define test cases
    char *test_strings[NBR_TESTS] = {
        "Hello,World,42",       	// Regular case with delimiter
        "Split this string",    	// Spaces as delimiters
        ",,,leading",           	// Leading delimiters
        "trailing,,,",          	// Trailing delimiters
        "",                    	 	// Empty string
	"^^^1^^2a,^^^^3^^^^--h^^^^"	// Special test case from francinette
    };
    char delimiters[NBR_TESTS] = {
        ',',                    // Comma delimiter
        ' ',                    // Space delimiter
        ',',                    // Comma delimiter
        ',',                    // Comma delimiter
        ' ',			// Space delimiter
	'^'			// Special case delimiter
    };
    char *expected_results[NBR_TESTS][5] = {
        {"Hello", "World", "42", NULL},
        {"Split", "this", "string", NULL},
        {"leading", NULL},
        {"trailing", NULL},
        {NULL},
	{"1", "2a,", "3", "--h", NULL}
    };

    int i = 0;
    while (i < NBR_TESTS)
    {
        char **res = ft_split(test_strings[i], delimiters[i]);

        // Check for allocation failure
        if (res == NULL)
        {
            fprintf(results, "ft_split: KO (Allocation failed on test %d)\n", i + 1);
            fprintf(results, "Input: \"%s\" with delimiter '%c'\n", test_strings[i], delimiters[i]);
            return;
        }

        // Compare result with expected output
        int j = 0;
        int pass = 1;
        while (expected_results[i][j] || res[j])
        {
            if ((!res[j] && expected_results[i][j]) || (res[j] && !expected_results[i][j]) ||
                (res[j] && expected_results[i][j] && strcmp(res[j], expected_results[i][j]) != 0))
            {
                pass = 0;  // Mismatch found
                break;
            }
            j++;
        }

        // Print only if the test fails
        if (!pass)
        {
            fprintf(results, "ft_split: KO (Mismatch on test %d)\n", i + 1);
            fprintf(results, "Input: \"%s\" with delimiter '%c'\n", test_strings[i], delimiters[i]);
            fprintf(results, "Expected: ");
            j = 0;
            while (expected_results[i][j])
            {
                fprintf(results, "\"%s\" ", expected_results[i][j]);
                j++;
            }
            fprintf(results, "\nGot: ");
            j = 0;
            while (res[j])
            {
                fprintf(results, "\"%s\" ", res[j]);
                j++;
            }
            fprintf(results, "\n");

            // Free memory and exit in case of mismatch
            j = 0;
            while (res[j])
            {
                free(res[j]);
                j++;
            }
            free(res);
            return;
        }

        // Free allocated memory for this test case if it passes
        j = 0;
        while (res[j])
        {
            free(res[j]);
            j++;
        }
        free(res);
        i++;
    }

    // All tests passed
    fprintf(results, "ft_split: SUCCESS\n");
}
