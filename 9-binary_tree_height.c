#include "binary_trees.h"

/**
 * get_height - get height of binary tree
 * @tree: Pointer to binary tree
 * Return: height of binary tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t leftHeight, rightHeight;

	if (tree == NULL)
		return (0);

	/* recursively measure height of the right and left nodes */
	leftHeight = get_height(tree->left);
	rightHeight = get_height(tree->right);

	/* return the longest height*/
	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	else
		return (rightHeight + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to binary tree
 * Return: height of binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* return calculated height minus 1*/
	return (get_height(tree) - 1);
}
