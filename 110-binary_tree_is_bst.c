#include "binary_trees.h"
#include "limits.h"

/**
 * validate_bst - Checks if a binary tree is a valid binary search tree.
 * @node: A pointer to the current node of the tree.
 * @min_val: The minimum valid value for the current node.
 * @max_val: The maximum valid value for the current node.
 *
 * Return: 1 if the tree rooted at 'node' is a valid BST, 0 otherwise.
 */
int validate_bst(const binary_tree_t *node, int min_val, int max_val)
{
	if (node != NULL)
	{
		if (node->n < min_val || node->n > max_val)
			return (0);
		return (validate_bst(node->left, min_val, node->n - 1) &&
			validate_bst(node->right, node->n + 1, max_val));

	}

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if 'tree' is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (validate_bst(tree, INT_MIN, INT_MAX));
}
