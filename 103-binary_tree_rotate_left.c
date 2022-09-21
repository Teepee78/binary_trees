#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on a binary tree
 * @tree: Pointer to binary tree
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tree_right = tree->right;

	if (tree == NULL)
		return (NULL);

	tree_right->parent = tree->parent;
	tree->parent = tree_right;
	tree->right = tree_right->left;
	tree_right->left = tree;

	return (tree_right);
}
