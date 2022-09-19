#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent node
 * is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

	/* insert node right of parent */
	/* check if parent has existing right node */
	if (parent->right == NULL)
		parent->right = new_node;
	else
	{
		/* assign existing right to temporary variable */
		temp = parent->right;
		/* set parent of existing right to new_node */
		temp->parent = new_node;
		/* set new_node as right of parent */
		parent->right = new_node;
		/* set existing right as right of new_node */
		new_node->right = temp;
	}

	return (new_node);
}
