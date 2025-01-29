/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:07:34 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 17:07:58 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>

void test_lstnew(FILE *results) {
    char *test_content = "Test content";
    t_list *node = ft_lstnew(test_content);  // Create a new node with content

    // Check if node is created and has the correct content and NULL next pointer
    if (node && node->content == test_content && node->next == NULL) {
        fprintf(results, "ft_lstnew: SUCCESS\n");
    } else {
        fprintf(results, "ft_lstnew: KO | ");
        if (!node)
            fprintf(results, "Returned NULL\n");
        else if (node->content != test_content)
            fprintf(results, "Content mismatch | Expected: \"%s\", Got: \"%s\"\n",
                    test_content, (char *)node->content);
        else if (node->next != NULL)
            fprintf(results, "Next pointer is not NULL\n");
    }

    // Free the allocated node if it was created
    free(node);
}

