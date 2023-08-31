#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: A pointer to the uncle node, or NULL if none.
 *
 * Description: This function determines the uncle node of the given node
 *              in the binary tree. If the input node is NULL, has no parent,
 *              or its parent has no parent (grandparent), the function returns
 *              NULL.Otherwise, it returns a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
