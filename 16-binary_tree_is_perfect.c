#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the tree to measure the height of.
 *
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t height_l = binary_tree_height(tree->left);
	size_t height_r = binary_tree_height(tree->right);

	return (((height_l > height_r) ? height_l : height_r) + 1);
}


/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */


int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (!tree->left && !tree->right)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
		    binary_tree_is_perfect(tree->right));
	}

	return (0);
}


