#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to binary tree
 * @func: function to be carried out on each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* call function on tree left */
	binary_tree_inorder(tree->left, func);

	/* call function on root */
	func(tree->n);

	/* call function on tree right */
	binary_tree_inorder(tree->right, func);
}
