#include "binary_trees.h"
/**
 * max - gets the node with max value in a tree
 *
 * @tree: pointer to tree
 * Return: maximum value
 */
int max(const binary_tree_t *tree)
{
	int max_value;
	int ret_left;
	int ret_right;

	if (tree->left == NULL && tree->right == NULL)
		return (tree->n);
	max_value = tree->n;
	if (tree->left != NULL)
	{
		ret_left = max(tree->left);
		if (ret_left > max_value)
			max_value = ret_left;
	}
	if (tree->right != NULL)
	{
		ret_right = max(tree->right);
		if (ret_right > max_value)
			max_value = ret_right;
	}
	return (max_value);
}
/**
 * min - gets the node with min value in a tree
 *
 * @tree: pointer to tree
 * Return: minimum value
 */
int min(const binary_tree_t *tree)
{
	int min_value;
	int ret_left;
	int ret_right;

	if (tree->left == NULL && tree->right == NULL)
		return (tree->n);
	min_value = tree->n;
	if (tree->left != NULL)
	{
		ret_left = min(tree->left);
		if (ret_left < min_value)
			min_value = ret_left;
	}
	if (tree->right != NULL)
	{
		ret_right = min(tree->right);
		if (ret_right < min_value)
			min_value = ret_right;
	}
	return (min_value);
}

/**
 * is_bst - checks if a binary tree is a bst tree
 *
 * @tree: pointer to binary tree
 * Return: 1 if bst else 0
 */
int is_bst(const binary_tree_t *tree)
{
	/*leaf node*/
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	/* iteratively checking for BST tree*/
	/*case where left and right nodes are not null*/
	if (tree->left != NULL && tree->right != NULL)
	{
		/*if (tree->left->n < tree->n && tree->right->n > tree->n)*/
		if (max(tree->left) < tree->n && min(tree->right) > tree->n)
		{
			if (is_bst(tree->left) && is_bst(tree->right))
				return (1);
		}
	}
	/*case where left node is null*/
	if (tree->left == NULL)
	{
		/*if (tree->right->n > tree->n)*/
		if (min(tree->right) > tree->n)
		{
			/*if (is_bst(tree->left) && is_bst(tree->right))*/
			if (is_bst(tree->right))
				return (1);
		}
	}
	/*case where right node is null*/
	if (tree->right == NULL)
	{
		/*if (tree->left->n < tree->n)*/
		if (max(tree->left) < tree->n)
		{
			/*if (is_bst(tree->left) && is_bst(tree->right))*/
			if (is_bst(tree->left))
				return (1);
		}
	}
	return (0);
}
/**
 * binary_tree_is_bst - checks if a binary tree is a bst tree
 *
 * @tree: pointer to binary tree
 * Return: 1 if bst else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree));
}
