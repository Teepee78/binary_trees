#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to binary tree to be deleted
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* recursively delete left node */
	binary_tree_delete(tree->left);
	/* recursively delete right node */
	binary_tree_delete(tree->right);

	/* delete root */
	free(tree);
}
