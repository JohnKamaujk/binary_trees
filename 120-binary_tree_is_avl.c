#include "binary_trees.h"
#include "limits.h"

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: If tree is NULL, return 0, else return height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + tree_height(tree->left) : 1;
		right_height = tree->right ? 1 + tree_height(tree->right) : 1;
		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * is_avl_tree - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited so far.
 * @max: The value of the largest node visited so far.
 *
 * Return: If the tree is a valid AVL tree, return 1, otherwise, return 0.
 */
int is_avl_tree(const binary_tree_t *tree, int min, int max)
{
	size_t left_height, right_height, height_diff;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		left_height = tree_height(tree->left);
		right_height = tree_height(tree->right);
		height_diff = left_height > right_height ? left_height -
				right_height : right_height - left_height;
		if (height_diff > 1)
			return (0);
		return (is_avl_tree(tree->left, min, tree->n - 1) &&
			is_avl_tree(tree->right, tree->n + 1, max));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_tree(tree, INT_MIN, INT_MAX));
}
