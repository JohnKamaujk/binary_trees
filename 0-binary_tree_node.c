#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: Pointer to the parent node of the new node.
 * @value: Value to be assigned to the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL){
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
		}

    new_node->parent = parent;
    new_node->value = value;
	

	return (new_node);
}

