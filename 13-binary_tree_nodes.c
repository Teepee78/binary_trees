#include "binary_trees.h"

/**
 *binary_tree_nodes - counts the number of nodes with at least one child
 *
 *@tree: Pointer to binary tree node
 *Return: number of nodes with at least one child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);
	/* check if the node has at least one child*/
	if (tree->left != NULL || tree->right != NULL)
	{
		size = size + 1;
	}
	/*
	 * recursively check all noes on left and right tree
	 * and their sums including the current node
	 */
	return (size + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
}
