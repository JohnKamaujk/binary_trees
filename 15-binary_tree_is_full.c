#include "binary_trees.h"

/**
 * is_full_subtree - Checks if a binary tree subtree is full recursively.
 * @subtree: A pointer to the root node of the subtree to check.
 *
 * Return: 1 if the subtree is full, 0 otherwise.
 */
int is_full_subtree(const binary_tree_t *subtree)
{
	if (subtree == NULL)
		return (1);

	if ((subtree->left != NULL && subtree->right == NULL) ||
	    (subtree->left == NULL && subtree->right != NULL))
		return (0);

	return (is_full_subtree(subtree->left) && is_full_subtree(subtree->right));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full_subtree(tree));
}
