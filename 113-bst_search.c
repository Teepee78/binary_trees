#include "binary_trees.h"

/**
 * bst_search - searches for a value in a binary tree
 * @tree: Pointer to binary tree
 * @value: value to be searched for
 * Return: pointer to node or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		temp = tree->left;
	else
		temp = tree->right;

	while (temp != NULL)
	{
		if (temp->n == value)
			return (temp);
		if (temp->right && value > temp->n)
			temp = temp->right;
		else if (temp->left && value < temp->n)
			temp = temp->left;
		else
			return (NULL);
	}

	return (NULL);
}
