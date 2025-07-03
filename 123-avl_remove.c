#include "binary_trees.h"

/**
 * min_value_node - finds smallest node in a subtree
 * @node:		subtree root
 *
 * Return:		pointer to the minimum node
 */
avl_t *min_value_node(avl_t *node)
{
	while (node && node->left)				/* walk to furthest left node */
		node = node->left;
	return (node);							/* return the minimum node */
}

/**
 * rebalance - rebalances a subtree after insertion or deletion
 * @root:		subtree root
 *
 * Return:		new root after rotation (or same one if already balanced)
 */
avl_t *rebalance(avl_t *root)
{
	int bf = binary_tree_balance(root);		/* get balance factor of the root */

	if (bf > 1)										/* left-heavy subtree */
	{
		if (binary_tree_balance(root->left) < 0)	/* left-right case */
			binary_tree_rotate_left(root->left);	/* rotate left */

		return (binary_tree_rotate_right(root));	/* final rotation */
	}

	if (bf < -1)									/* right-heavy subtree */
	{
		if (binary_tree_balance(root->right) > 0)	/* right-left case */
			binary_tree_rotate_right(root->right);	/* rotate right */

		return (binary_tree_rotate_left(root));		/* final rotation */
	}

	return (root);					/* return the root if already balanced */
}

/**
 * avl_remove - removes a value from an AVL tree
 * @root:		root node of the AVL tree
 * @value:		value to remove
 *
 * Return: pointer to the new root node (or NULL if tree empty)
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)								/* if tree empty, return NULL */
		return (NULL);

	if (value < root->n)					/* if value less, go left */
		root->left = avl_remove(root->left, value);
	else if (value > root->n)				/* if value greater, go right */
		root->right = avl_remove(root->right, value);
	else									/* when value found */
	{
		avl_t *tmp;							/* temp ptr */

		if (!root->left || !root->right)	/* if node has one/no children */
		{
			tmp = root->left ? root->left : root->right;	/* get child */
			if (tmp)
				tmp->parent = root->parent;
			free(root);						/* free the node */
			root = tmp;						/* update root to child or NULL */
		}

		else								/* if node has two children */
		{
			tmp = min_value_node(root->right);	/* min node in right sub */
			root->n = tmp->n;			/* set current node's val to min's */
			root->right = avl_remove(root->right, tmp->n);	/* remove min  */
		}
	}

	if (root)								/* if root !NULL after removal */
		root = rebalance(root);				/* rebalance the tree */

	return (root);							/* return the new root node */
}
