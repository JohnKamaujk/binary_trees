#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root in a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a root, 0 otherwise.
 *
 * Description: Determines whether the given node is a root node
 *              in a binary tree.A root node is a node that has
 *              no parent and is the topmost node in the tree.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->parent == NULL)
		return (1);

	return (0);
}
