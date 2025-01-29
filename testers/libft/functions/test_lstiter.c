/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:41:30 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 21:41:36 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to apply to each element, modifying the content
void append_suffix(void *content) {
    if (content) {
        strcat((char *)content, " - modified");
    }
}

// Test function for ft_lstiter
void test_lstiter(FILE *results) {
    // Setup: Create a list with multiple nodes
    t_list *head = ft_lstnew(strdup("Node 1"));
    t_list *second = ft_lstnew(strdup("Node 2"));
    t_list *third = ft_lstnew(strdup("Node 3"));

    if (!head || !second || !third) {
        fprintf(results, "ft_lstiter: KO | Memory allocation failed\n");
        free(head); free(second); free(third);  // Clean up any partially allocated nodes
        return;
    }

    // Link the nodes
    head->next = second;
    second->next = third;

    // Run ft_lstiter to apply append_suffix to each node's content
    ft_lstiter(head, append_suffix);

    // Verify if each node's content was modified as expected
    if (strcmp(head->content, "Node 1 - modified") == 0 &&
        strcmp(second->content, "Node 2 - modified") == 0 &&
        strcmp(third->content, "Node 3 - modified") == 0) {
        fprintf(results, "ft_lstiter: SUCCESS\n");
    } else {
        fprintf(results, "ft_lstiter: KO | Contents were not modified correctly\n");
    }

    // Free the list nodes
    ft_lstclear(&head, free);
}
