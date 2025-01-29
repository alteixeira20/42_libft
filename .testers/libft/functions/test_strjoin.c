/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:13:01 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/05 21:33:49 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../tester.h"

#define NUM_TESTS 4

void test_strjoin(FILE *results) 
{
    // Define test cases without NULL values
    char *test_s1[NUM_TESTS] = {"Hello", "42", "", "Hello"};
    char *test_s2[NUM_TESTS] = {" World", " Network", "World", ""};
    char *expected_results[NUM_TESTS] = {"Hello World", "42 Network", "World", "Hello"};

    int i = 0;
    while (i < NUM_TESTS)
    {
        char *res = ft_strjoin(test_s1[i], test_s2[i]);

        // Check for allocation failure
        if (res == NULL) 
        {
            fprintf(results, "ft_strjoin: KO (Allocation failed on test %d)\n", i + 1);
            fprintf(results, "Input: s1=\"%s\", s2=\"%s\"\n", test_s1[i], test_s2[i]);
            return;
        }

        // Compare result with expected output
        if (strcmp(res, expected_results[i]) != 0) 
        {
            fprintf(results, "ft_strjoin: KO (Mismatch on test %d)\n", i + 1);
            fprintf(results, "Input: s1=\"%s\", s2=\"%s\"\n", test_s1[i], test_s2[i]);
            fprintf(results, "Expected: \"%s\", Got: \"%s\"\n", expected_results[i], res);
            free(res);
            return;
        }

        // Free allocated memory and continue
        free(res);
        i++;
    }

    // All tests passed
    fprintf(results, "ft_strjoin: SUCCESS\n");
}
