#include "binary_trees.h"
/**
 * binary_tree_size - Measures the size of a binary tree
 *
 *@tree: Pointer to binary tree node
 *Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size;
	size_t right_size;

	if (tree == NULL)
		return (0);
	/* recursively count the number of nodes on left sub tree */
	left_size = 1 + binary_tree_size(tree->left);
	/* recursively count the number of nodes on right sub tree */
	right_size = 1 + binary_tree_size(tree->right);
	/* return the total number of nodes, subtract 1 */
	/* as the root is counted two times */
	return (left_size + right_size - 1);
}
/**
 * check_complete - checks if a binary tree is complete recursively
 *
 * @index: current index
 * @tree: Pointer to binary tree
 * @nodes: number of nodes in a binary tree
 * Return: 1 if complete else 0
 */
int check_complete(const binary_tree_t *tree, size_t index, size_t nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	return (check_complete(tree->left, 2 * index + 1, nodes) &&
		check_complete(tree->right, 2 * index + 2, nodes));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to binary tree
 * Return: 1 if complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);
	nodes = binary_tree_size(tree);
	return (check_complete(tree, 0, nodes));
}
