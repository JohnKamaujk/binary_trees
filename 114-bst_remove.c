#include "binary_trees.h"

bst_t *find_inorder_successor(bst_t *root);
bst_t *delete_bst_node(bst_t *root, bst_t *node);
bst_t *recursive_bst_remove(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * find_inorder_successor - Finds minimum value node in a binary search tree.
 * @root: A pointer to the root node of the BST.
 *
 * Return: A pointer to the minimum value node in the BST.
 */
bst_t *find_inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * delete_bst_node - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *delete_bst_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No left child or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = find_inorder_successor(node->right);
	node->n = successor->n;

	return (delete_bst_node(root, successor));
}

/**
 * recursive_bst_remove - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *recursive_bst_remove(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete_bst_node(root, node));
		if (node->n > value)
			return (recursive_bst_remove(root, node->left, value));
		return (recursive_bst_remove(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove_custom - Removes a node with a specified value from bst
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (recursive_bst_remove(root, root, value));
}
