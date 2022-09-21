#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree
 * @tree: Pointer to binary tree
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tree_parent;
	binary_tree_t *tree_right;

	if (tree == NULL)
		return (NULL);
	tree_parent = tree->parent;
	tree_right = tree->right;
	if (tree_right == NULL)
		return (tree);

	tree_right->parent = tree->parent;
	tree->parent = tree_right;
	if (tree_right->left)
		tree_right->left->parent = tree;
	/* check if tree is right or left node */
	if (tree_parent != NULL)
	{
		if (tree_parent->right == tree)
			tree_parent->right = tree_right;
		else if (tree_parent->left == tree)
			tree_parent->left = tree_right;
	}
	tree->right = tree_right->left;
	tree_right->left = tree;

	return (tree_right);
}
