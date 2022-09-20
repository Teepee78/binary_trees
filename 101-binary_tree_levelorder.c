#include "binary_trees.h"
/**
 * binary_tree_sibling - returns the sibling of a node
 *
 * @node: node in binary tree
 * Return: sibiling of node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	/* Check if node is null */
	if (node == NULL)
		return (NULL);
	/* Check if root node */
	if (node->parent == NULL)
		return (NULL);

	/* Find sibling of Node */
	if (node->parent->right != node)
		sibling = node->parent->right;
	else if (node->parent->left != node)
		sibling = node->parent->left;
	return (sibling);
}
/**
 * binary_tree_levelorder - traverses a tree in level order
 *
 * @tree: Pointer to binary tree
 * @func: function to be carried out on each node of binary tree
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *sibling;

	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	sibling = binary_tree_sibling((binary_tree_t *) tree);
	if (sibling != NULL)
		func(sibling->n);
	binary_tree_levelorder(tree->left, func);
	if (sibling != NULL)
		binary_tree_levelorder(sibling->left, func);
}
