#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to binary tree node
 * Return: depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *temp;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	/* check how many parents a node has */
	temp = tree->parent;
	while (temp != NULL)
	{
		depth++;
		temp = temp->parent;
	}

	return (depth);
}
