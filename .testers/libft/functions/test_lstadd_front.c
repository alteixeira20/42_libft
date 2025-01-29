/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:15:24 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 18:15:28 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>

void test_lstadd_front(FILE *results) {
    // Initial setup for the test
    char *initial_content = "Initial node";
    char *new_content = "New front node";
    
    // Create the initial list with one node
    t_list *initial_node = ft_lstnew(initial_content);
    t_list *new_node = ft_lstnew(new_content);

    // Add the new node to the front of the list
    ft_lstadd_front(&initial_node, new_node);

    // Check if the new node is now the first node in the list
    if (initial_node == new_node && new_node->content == new_content && new_node->next != NULL && new_node->next->content == initial_content) {
        fprintf(results, "ft_lstadd_front: SUCCESS\n");
    } else {
        fprintf(results, "ft_lstadd_front: KO | ");
        if (initial_node != new_node)
            fprintf(results, "New node was not added to the front\n");
        else if (new_node->content != new_content)
            fprintf(results, "Content mismatch in new node | Expected: \"%s\", Got: \"%s\"\n",
                    new_content, (char *)new_node->content);
        else if (new_node->next == NULL)
            fprintf(results, "New node's next pointer is NULL\n");
        else if (new_node->next->content != initial_content)
            fprintf(results, "Original node content mismatch | Expected: \"%s\", Got: \"%s\"\n",
                    initial_content, (char *)new_node->next->content);
    }

    // Free both nodes to prevent memory leaks
    free(initial_node->next);  // Free the original node
    free(initial_node);         // Free the new node added to the front
}
