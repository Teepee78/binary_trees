#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree
 * @tree: Pointer to binary tree
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tree_parent = tree->parent;
	binary_tree_t *tree_right = tree->right;

	if (tree == NULL || tree_right == NULL)
		return (NULL);

	tree_right->parent = tree->parent;
	tree->parent = tree_right;
	/* check if tree is right or left node */
	if (tree_parent != NULL)
	{
		if (tree_parent->right == tree)
			tree_parent->right = tree_right;
		else if (tree_parent->left == tree)
			tree_parent->left = tree_right;
	}
	tree->right = tree_right->left;
	tree->right->parent = tree;
	tree_right->left = tree;

	return (tree_right);
}
