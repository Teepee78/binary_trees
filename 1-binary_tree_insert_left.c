#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent node
 * is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	if (parent == NULL)
		return (NULL);

	/* create node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	/* insert node left of parent */
	/* check if parent has existing left node */
	if (parent->left == NULL)
		parent->left = new_node;
	else
	{
		/* assign existing left to temporary variable */
		temp = parent->left;
		/* set parent of existing left to new_node */
		temp->parent = new_node;
		/* set new_node as left of parent */
		parent->left = new_node;
		/* set existing left as left of new_node */
		new_node->left = temp;
	}

	return (new_node);
}
