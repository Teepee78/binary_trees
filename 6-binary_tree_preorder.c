#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to binary tree
 * @func: function to be carried out on each node of binary tree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* call function on root */
	func(tree->n);

	/* call function on tree left */
	binary_tree_preorder(tree->left, func);
	/* call function on tree right */
	binary_tree_preorder(tree->right, func);
}
