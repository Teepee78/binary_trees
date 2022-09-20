#include "binary_trees.h"

/**
 *binary_tree_leaves - Countes the number of leaves in a tree
 *
 *@tree: Pointer to binary tree node
 *Return: number of leaves in tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);
	/*
	 * check if the left and right child of a node are
	 * null, this indicates a leaf
	 */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	/* recursively check the left subtree for leaf nodes */
	left_size = left_size + binary_tree_leaves(tree->left);
	/* recursively check the right subtree for leaf nodes */
	right_size = right_size + binary_tree_leaves(tree->right);
	return (left_size + right_size);
}
