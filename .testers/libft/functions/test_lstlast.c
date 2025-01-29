/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:34:10 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 19:35:39 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>

void test_lstlast(FILE *results) {
    int all_passed = 1;

    // Test Case 1: List with multiple nodes
    t_list *node1 = ft_lstnew("First");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("Third");

    node1->next = node2;
    node2->next = node3;

    t_list *last = ft_lstlast(node1);
    if (last != node3 || last->content != node3->content) {
        fprintf(results, "ft_lstlast (multiple nodes): KO | Expected content: \"Third\", Got: \"%s\"\n", (char *)last->content);
        all_passed = 0;
    }

    // Test Case 2: List with one node
    last = ft_lstlast(node3);
    if (last != node3 || last->content != node3->content) {
        fprintf(results, "ft_lstlast (single node): KO | Expected content: \"Third\", Got: \"%s\"\n", (char *)last->content);
        all_passed = 0;
    }

    // Test Case 3: Empty list (NULL)
    last = ft_lstlast(NULL);
    if (last != NULL) {
        fprintf(results, "ft_lstlast (NULL): KO | Expected: NULL, Got: non-NULL\n");
        all_passed = 0;
    }

    // Print success message if all tests pass
    if (all_passed) {
        fprintf(results, "ft_lstlast: SUCCESS\n");
    }

    // Free the allocated nodes
    free(node1);
    free(node2);
    free(node3);
}
