#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to binary tree node
 * Return: depth of node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *temp;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	/* check how many parents a node has */
	temp = tree->parent;
	while (temp != NULL)
	{
		depth++;
		temp = temp->parent;
	}

	return (depth);
}

/**
 *binary_trees_ancestor - determines the least common ancestor of two nodes
 *
 *@first: first node
 *@second: second node
 *Return: pointer to lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	binary_tree_t *temp_first = (binary_tree_t *) first;
	binary_tree_t *temp_second = (binary_tree_t *) second;

	if (first == NULL || second == NULL)
		return (NULL);

	if (temp_first == temp_second)
		return (temp_first);

	/* Making the depth of the temp_first and temp_second equal */
	/* Case where first has a higher depth */
	while (binary_tree_depth(temp_first) > binary_tree_depth(temp_second))
	{
		temp_first = temp_first->parent;
		/* case where temp_second or second is the ancestor */
		if (temp_first == temp_second)
			return (temp_first);
	}
	/* Making the depth of the temp_first and temp_second equal */
	/* Case where second has a higher depth */
	while (binary_tree_depth(temp_second) > binary_tree_depth(temp_first))
	{
		temp_second = temp_second->parent;
		/* case where temp_first or first is the ancestor */
		if (temp_first == temp_second)
			return (temp_first);
	}
	/* Iterate until root until parent is found */
	while (temp_first != NULL)
	{
		temp_first = temp_first->parent;
		temp_second = temp_second->parent;
		if (temp_first == temp_second)
			return (temp_first);
	}
	return (NULL);

}
