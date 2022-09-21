#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from array
 * @array: array of integers
 * @size:  size of array
 * Return: pointer to root node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (size == 0 || array == NULL)
		return (NULL);

	root = bst_insert(&root, array[0]);

	if (size == 1)
		return (root);

	for (i = 1; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
