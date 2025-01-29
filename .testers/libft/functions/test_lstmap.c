#include "../tester.h"
#include "../tester.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to apply to each element in ft_lstmap (duplicates and appends text)
void *duplicate_and_append(void *content) {
    char *new_content = malloc(strlen((char *)content) + 15); // Allocate memory for new content
    if (new_content) {
        strcpy(new_content, (char *)content);
        strcat(new_content, " - mapped");
    }
    return new_content;
}

// Custom delete function to free content
void del_function(void *content) {
    free(content);
}

// Test function for ft_lstmap
void test_lstmap(FILE *results) {
    // Setup: Create an initial list with multiple nodes
    t_list *original = ft_lstnew(strdup("Node 1"));
    t_list *second = ft_lstnew(strdup("Node 2"));
    t_list *third = ft_lstnew(strdup("Node 3"));
    
    if (!original || !second || !third) {
        fprintf(results, "ft_lstmap: KO | Memory allocation failed\n");
        ft_lstclear(&original, del_function);  // Clean up if setup fails
        return;
    }

    // Link the nodes in the original list
    original->next = second;
    second->next = third;

    // Run ft_lstmap to create a new list with modified content
    t_list *mapped_list = ft_lstmap(original, duplicate_and_append, del_function);

    // Verify that the mapped list contains correctly modified content
    if (mapped_list &&
        strcmp(mapped_list->content, "Node 1 - mapped") == 0 &&
        strcmp(mapped_list->next->content, "Node 2 - mapped") == 0 &&
        strcmp(mapped_list->next->next->content, "Node 3 - mapped") == 0 &&
        mapped_list->next->next->next == NULL) {
        fprintf(results, "ft_lstmap: SUCCESS\n");
    } else {
        fprintf(results, "ft_lstmap: KO | Mapped list content incorrect or structure invalid\n");
    }

    // Verify that the original list remains unchanged
    if (strcmp(original->content, "Node 1") != 0 ||
        strcmp(second->content, "Node 2") != 0 ||
        strcmp(third->content, "Node 3") != 0) {
        fprintf(results, "ft_lstmap: KO | Original list was modified\n");
    }

    // Clean up
    ft_lstclear(&original, del_function);
    ft_lstclear(&mapped_list, del_function);
}
