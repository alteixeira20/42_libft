/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:11:37 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 19:11:44 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>

void test_lstsize(FILE *results) {
    int all_passed = 1;  // Flag to track if all tests pass

    // Initial setup for the test cases
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    // Link the nodes to form a list of size 3
    node1->next = node2;
    node2->next = node3;

    // Test case 1: List with three nodes
    int size = ft_lstsize(node1);
    if (size != 3) {
        fprintf(results, "ft_lstsize (3 nodes): KO | Expected: 3, Got: %d\n", size);
        all_passed = 0;
    }

    // Test case 2: List with one node
    size = ft_lstsize(node3);
    if (size != 1) {
        fprintf(results, "ft_lstsize (1 node): KO | Expected: 1, Got: %d\n", size);
        all_passed = 0;
    }

    // Test case 3: Empty list (NULL)
    size = ft_lstsize(NULL);
    if (size != 0) {
        fprintf(results, "ft_lstsize (NULL): KO | Expected: 0, Got: %d\n", size);
        all_passed = 0;
    }

    // Print success message only if all tests pass
    if (all_passed) {
        fprintf(results, "ft_lstsize: SUCCESS\n");
    }

    // Free the allocated nodes to prevent memory leaks
    free(node1);
    free(node2);
    free(node3);
}
