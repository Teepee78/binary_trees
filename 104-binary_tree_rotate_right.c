#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs right rotation on a binary tree
 * @tree: Pointer to binary tree
 * Return: new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tree_parent;
	binary_tree_t *tree_left;

	if (tree == NULL)
		return (NULL);
	tree_parent = tree->parent;
	tree_left = tree->left;
	if (tree_left == NULL)
		return (tree);

	tree_left->parent = tree->parent;
	tree->parent = tree_left;
	if (tree_left->right)
		tree_left->right->parent = tree;
	/* check if tree is right or left node */
	if (tree_parent != NULL)
	{
		if (tree_parent->right == tree)
			tree_parent->right = tree_left;
		else if (tree_parent->left == tree)
			tree_parent->left = tree_left;
	}
	tree->left = tree_left->right;
	tree_left->right = tree;

	return (tree_left);
}
