#include "binary_trees.h"

/**
 * array_to_bst - Constructs a Binary Search Tree (BST) from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	/* Check if the input array is NULL */
	if (array == NULL)
		return (NULL);

	/* Loop through the array elements */
	for (i = 0; i < size; i++)
	{
		/* Check if the current element already exists in the tree */
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		/* If the current element is unique */
		if (j == i)
		{
			/* Insert the current element into the BST */
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	/* Return the root node of the created BST */
	return (tree);
}
