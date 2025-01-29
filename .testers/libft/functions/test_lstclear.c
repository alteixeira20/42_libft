/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:24:29 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 21:26:40 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>

// Custom delete function to free content
static void del_function(void *content) {
    free(content);
}

// Test function for ft_lstclear
void test_lstclear(FILE *results) {
    // Setup: Create a list with multiple nodes
    t_list *head = ft_lstnew(malloc(20));
    t_list *second = ft_lstnew(malloc(20));
    t_list *third = ft_lstnew(malloc(20));

    if (!head || !second || !third) {
        fprintf(results, "ft_lstclear: KO | Memory allocation failed\n");
        free(head); free(second); free(third);  // Clean up any partially allocated nodes
        return;
    }

    snprintf(head->content, 20, "Node 1");
    snprintf(second->content, 20, "Node 2");
    snprintf(third->content, 20, "Node 3");

    head->next = second;
    second->next = third;

    // Run ft_lstclear to delete all nodes
    ft_lstclear(&head, del_function);

    // Verify if all nodes were freed and head is set to NULL
    if (head == NULL) {
        fprintf(results, "ft_lstclear: SUCCESS\n");
    } else {
        fprintf(results, "ft_lstclear: KO | Head pointer was not set to NULL\n");
    }
}
