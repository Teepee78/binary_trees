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
 * get_nodeToDelete - determines node to delete
 *
 * @root: pointer to binary tree
 * @value: value to be deleted
 * Return: node to be deleted
 */
bst_t *get_nodeToDelete(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);
	if (root->n == value)
		return (root);
	else if (value > root->n)
		return (get_nodeToDelete(root->right, value));
	else
		return (get_nodeToDelete(root->left, value));
}
/**
 * deleteWithChild - deletes nodes that have children
 *
 * @delete: node to delete
 * @parent: parent of node to delete
 * Return:
 */
void deleteWithChild(bst_t *delete, bst_t *parent)
{
	bst_t *temp;

	if (delete->left == NULL && delete->right) /* delete has only one child */
	{
		temp = delete->right;
		if (parent) /* check if delete is left or right child */
		{
			if (parent->left && parent->left == delete)
				parent->left = temp;
			else
				parent->right = temp;
		}
		temp->parent = parent;
	}
	else if (delete->right == NULL && delete->left)
	{
		temp = delete->left;
		if (parent) /* check if delete is left or right child */
		{
			if (parent->left && parent->left == delete)
				parent->left = temp;
			else
				parent->right = temp;
		}
		temp->parent = parent;
	}
	else
	{ /* delete has two nodes */
		temp = minValueNode(delete->right);
		delete->n = temp->n;
		if (temp->right != NULL)/* delete temp, check if temp is has a right child */
		{
			temp->parent->left = temp->right;
			temp->right->parent = temp->parent;
		} /* temp has no child */
		else
			temp->parent->left = NULL;
		delete = temp;
	}
	free(delete);
}
/**
 * bst_remove - removes a node from a binary tree
 * @root: root of binary tree
 * @value: value of node
 * Return: pointer to new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *parent, *delete;

	if (root == NULL)
		return (NULL);
	delete = get_nodeToDelete(root, value);
	if (delete == NULL)
		return (root);
	parent = delete->parent;
	if (delete->left == NULL && delete->right == NULL) /* delete has no child */
	{ /* checking left or right child */
		if (parent)
		{
			if (parent->left && parent->left == delete)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		free(delete);
	}
	else
		deleteWithChild(delete, parent);
	return (root);
}
