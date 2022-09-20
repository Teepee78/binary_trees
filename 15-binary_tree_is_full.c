#include "binary_trees.h"

/**
 *binary_tree_is_full - checks if a binary tree is full
 *
 *@tree: Pointer to binary tree
 *Return: 1 if tree is full else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Checking if its a leaf node */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/* Checking if its full*/
	if (tree->left != NULL && tree->right != NULL)
		/* Checking if the left and right subtree are full*/
		if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
			return (1);
	return (0);
}
