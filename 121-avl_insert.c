#include "binary_trees.h"

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: Pointer to AVL tree
 * @value: value to be inserted
 * Return: pointer to created node or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *parent = NULL, *new_node, *temp = NULL, *ancestor;
	int balance;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	/* search for parent node to insert value in */
	temp = *tree;
	while (temp != NULL)
	{
		parent = temp;
		if (temp->n > value)
			temp = temp->left;
		else if (temp->n < value)
			temp = temp->right;
	}
	/* check if to insert in left or right */
	if (parent->n > value)
	{
		/* we are on the left */
		new_node = binary_tree_node(parent, value);
		parent->left = new_node;
	} else if (parent->n < value)
	{
		/* we are on the right */
		new_node = binary_tree_node(parent, value);
		parent->right = new_node;
	}
	/* check balance */
	ancestor = parent->parent;
	balance = binary_tree_balance(ancestor);
	if (balance > 1)
	{
		/* left is the unbalanced, right rotation */
		if (new_node == parent->right)
			binary_tree_rotate_left(parent);
		binary_tree_rotate_right(ancestor);
	} else if (balance < -1)
	{
		/* right is the unbalanced, left rotation */
		if (new_node == parent->left)
			binary_tree_rotate_right(parent);
		binary_tree_rotate_left(ancestor);
	}

	return (new_node);
}
