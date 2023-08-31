#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t node_depth(const binary_tree_t *node);
const binary_tree_t *find_leaf(const binary_tree_t *tree);
int is_tree_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * node_depth - Calculates the depth of a node in a binary tree.
 * @node: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 */
size_t node_depth(const binary_tree_t *node)
{
	return (node->parent != NULL ? 1 + node_depth(node->parent) : 0);
}

/**
 * find_leaf - Finds a leaf node in a binary tree.
 * @tree: A pointer to the root node of the tree to search in.
 *
 * Return: A pointer to the first encountered leaf node.
 */
const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree))
		return (tree);
	return (tree->left ? find_leaf(tree->left) : find_leaf(tree->right));
}

/**
 * is_tree_perfect - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of a leaf node in the binary tree.
 * @level: The current level of the node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_tree_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_tree_perfect(tree->left, leaf_depth, level + 1) &&
		is_tree_perfect(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_tree_perfect(tree, node_depth(find_leaf(tree)), 0));
}
