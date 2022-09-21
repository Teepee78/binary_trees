#include "binary_trees.h"

/**
 * get_height - get height of binary tree
 * @tree: Pointer to binary tree
 * Return: height of binary tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t leftHeight, rightHeight;

	if (tree == NULL)
		return (0);

	/* recursively measure height of the right and left nodes */
	leftHeight = get_height(tree->left);
	rightHeight = get_height(tree->right);

	/* return the longest height*/
	if (leftHeight > rightHeight)
		return (leftHeight + 1);
	else
		return (rightHeight + 1);
}

/**
 * funcCurrentLevel - calls function on current level
 * @tree: Pointer to binary tree
 * @level: level which function should be called
 * @func: function to be called
 */
void funcCurrentLevel(const binary_tree_t *tree, size_t level,
											void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		/* recursively call func on children node */
		funcCurrentLevel(tree->left, level - 1, func);
		funcCurrentLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using level order traversal
 * @tree: Pointer to binary tree
 * @func: function to be carried out on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = get_height(tree), i;

	if (tree == NULL || func == NULL)
		return;

	for (i = 1; i <= height; i++)
		funcCurrentLevel(tree, i, func);
}
