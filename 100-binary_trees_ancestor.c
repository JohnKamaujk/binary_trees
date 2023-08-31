#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor, or NULL if none.
 *
 * Description: This function determines the lowest common ancestor node
 *              of the given two nodes in the binary tree. If no common
 *              ancestor is found, it returns NULL. Otherwise, it
 *              returns a pointer to the lowest common ancestor node.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor_first, *ancestor_second;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	ancestor_first = first->parent;
	ancestor_second = second->parent;

	if (first == ancestor_second || !ancestor_first || (!ancestor_first->parent
		&& ancestor_second))
		return (binary_trees_ancestor(first, ancestor_second));
	else if (ancestor_first == second || !ancestor_second ||
		(!ancestor_second->parent && ancestor_first))
		return (binary_trees_ancestor(ancestor_first, second));

	return (binary_trees_ancestor(ancestor_first, ancestor_second));
}
