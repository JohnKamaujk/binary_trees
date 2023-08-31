#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: A pointer to the sibling node, or NULL if none.
 *
 * Description: This function determines the sibling node of the given node
 *              in the binary tree. If the input node is NULL or has no parent,
 *              or if there is no sibling, the function returns NULL.
 *              Otherwise, it returns a pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
