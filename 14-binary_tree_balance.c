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

	return ((height_l > height_r) ? height_l : height_r + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the tree to measure the balance factor of.
 *
 * Return: Balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	int height_l = binary_tree_height(tree->left);
	int height_r = binary_tree_height(tree->right);

	return (height_l - height_r);
}
