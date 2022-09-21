#include "binary_trees.h"

/**
 * is_bst - checks if a binary tree is a binary search tree
 * @tree: Pointer to binary tree
 * @n: root value
 * @left: left or right
 * Return: 1 if it is a valid BST else 0
 */
int is_bst(const binary_tree_t *tree, int n, int left)
{
	int retval_left = 1, retval_right = 1, retval = 1;

	if (tree == NULL)
		return (1);

	if (left == 1)
	{
		/* we are in a node on the left */
		if (tree->left && (tree->n < tree->left->n || n < tree->left->n))
			retval = 0;
		if (tree->right && (tree->n > tree->right->n || n < tree->right->n))
			retval = 0;
	} else if (left == 0)
	{
		/* we are in a node on the right */
		if (tree->left && (tree->n < tree->left->n || n > tree->left->n))
			retval = 0;
		if (tree->right && (tree->n > tree->right->n || n > tree->right->n))
			retval = 0;
	} else
	{
		/* we are in root node */
		if (tree->left && (tree->n < tree->left->n || n < tree->left->n))
			retval = 0;
		if (tree->right && (tree->n > tree->right->n || n > tree->right->n))
			retval = 0;
	}

	/* Check if tree nodes are valid BSTs */
	if (tree->left)
		retval_left = is_bst(tree->left, n, 1);
	if (tree->right)
		retval_right = is_bst(tree->right, n, 0);

	if (retval == 1 && retval_left == 1 && retval_right == 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a binary search tree
 * @tree: Pointer to binary tree
 * Return: 1 if it is a valid BST else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, tree->n, 2));
}
