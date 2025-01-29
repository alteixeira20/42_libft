/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:50:30 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 19:50:36 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>

void test_lstadd_back(FILE *results) {
    int all_passed = 1;

    // Test Case 1: Add to an empty list
    t_list *head = NULL;
    t_list *new_node1 = ft_lstnew("First");

    ft_lstadd_back(&head, new_node1);
    if (head != new_node1 || head->content != new_node1->content) {
        fprintf(results, "ft_lstadd_back (empty list): KO | Expected content: \"First\", Got: \"%s\"\n", (char *)head->content);
        all_passed = 0;
    }

    // Test Case 2: Add to a list with one node
    t_list *new_node2 = ft_lstnew("Second");
    ft_lstadd_back(&head, new_node2);
    if (head->next != new_node2 || head->next->content != new_node2->content) {
        fprintf(results, "ft_lstadd_back (1 node list): KO | Expected content: \"Second\" at end, Got: \"%s\"\n", (char *)head->next->content);
        all_passed = 0;
    }

    // Test Case 3: Add to a list with multiple nodes
    t_list *new_node3 = ft_lstnew("Third");
    ft_lstadd_back(&head, new_node3);
    if (head->next->next != new_node3 || head->next->next->content != new_node3->content) {
        fprintf(results, "ft_lstadd_back (2 node list): KO | Expected content: \"Third\" at end, Got: \"%s\"\n", (char *)head->next->next->content);
        all_passed = 0;
    }

    // Print success message if all tests pass
    if (all_passed) {
        fprintf(results, "ft_lstadd_back: SUCCESS\n");
    }

    // Free the allocated nodes
    free(head->next->next);  // Free third node
    free(head->next);        // Free second node
    free(head);              // Free first node
}
