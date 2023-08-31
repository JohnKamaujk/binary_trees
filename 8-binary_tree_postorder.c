#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func); /* Traverse left subtree */
	binary_tree_postorder(tree->right, func); /* Traverse right subtree */
	func(tree->n); /* Call function for current node's value */
}
