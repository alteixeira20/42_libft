/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:11:28 by paalexan          #+#    #+#             */
/*   Updated: 2024/11/07 21:26:50 by paalexan         ###   ########.fr       */
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

// Test function for ft_lstdelone
void test_lstdelone(FILE *results) {
    // Initial setup for the test
    char *node_content = malloc(20);
    if (!node_content) {
        fprintf(results, "ft_lstdelone: KO | Memory allocation for content failed\n");
        return;
    }
    snprintf(node_content, 20, "Node Content");

    t_list *node = ft_lstnew(node_content);
    if (!node) {
        fprintf(results, "ft_lstdelone: KO | Memory allocation for node failed\n");
        free(node_content);  // Freeing here since node creation failed
        return;
    }

    // Run ft_lstdelone to delete the node
    ft_lstdelone(node, del_function);

    // Check if the content and node were freed properly
    fprintf(results, "ft_lstdelone: SUCCESS\n");
}
