#include "binary_trees.h"

/**
 * minValueNode - locates leftest node on the right
 * @root: root node
 * Return: leftest node
 */
bst_t *minValueNode(bst_t *root)
{
	bst_t *temp;

	for (temp = root; temp->left != NULL; temp = temp->left)
	{}
	return (temp);
}
/**
 * bst_remove - removes a node from a binary tree
 * @root: root of binary tree
 * @value: value of node
 * Return: pointer to new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent, *retval = NULL;

	if (root == NULL)
		return (NULL);
	parent = root->parent;
	/* node to be deleted is at the left */
	if (root->n > value)
		retval = bst_remove(root->left, value);
	/* node to be deleted is at the right */
	else if (root->n < value)
		retval = bst_remove(root->right, value);
	/* node to be deleted is equal to root */
	else
	{
		/* root has only one child */
		if (root->left == NULL && root->right)
		{
			temp = root->right;
			/* check if root is left or right child */
			if (parent)
			{
				if (parent->left && parent->left == root)
					parent->left = temp;
				else
					parent->right = temp;
			}
			temp->parent = parent;
			/*temp->left = root->left;*/
		} else if (root->right == NULL && root->left)
		{
			temp = root->left;
			/* check if root is left or right child */
			if (parent)
			{
				if (parent->left && parent->left == root)
					parent->left = temp;
				else
					parent->right = temp;
			}
			temp->parent = parent;
		} else  /* root has two nodes */
		{
			temp = minValueNode(root->right);
			/* check if root is left or right child */
			if (parent)
			{
				if (parent->left && parent->left == root)
					parent->left = temp;
				else
					parent->right = temp;
			}
			temp->parent->left = NULL;
			temp->right = temp->parent;
			temp->parent = parent;
			temp->left = root->left;
			root->left->parent = temp;
		}
		free(root);
		/* find root */
		while (temp->parent != NULL)
			temp = temp->parent;
		return (temp);
	}
	return (retval);
}
