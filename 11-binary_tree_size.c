#include "binary_trees.h"

/**
 *binary_tree_size - Measures the size of a binary tree
 *
 *@tree: Pointer to binary tree node
 *Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;

	if (tree == NULL)
		return (0);
	/* recursively count the number of nodes on left sub tree */
	left_size = 1 + binary_tree_size(tree->left);
	/* recursively count the number of nodes on right sub tree */
	right_size = 1 + binary_tree_size(tree->right);
	/* return the total number of nodes, subtract 1 */
	/* as the root is counted two times */
	return (left_size + right_size - 1);
}
