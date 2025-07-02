#include "binary_trees.h"

/**
 * rebalance_up - rebalance an AVL tree from given node up to root
 * @tree:		address of the AVL root pointer (could change)
 * @node:		starting node (parent of inserted node)
 * @value:		value that was inserted to detect LR / RL cases.
 */
void rebalance_up(avl_t **tree, avl_t *node, int value)
{
	avl_t *curr = node, *pivot;			/* current node (to check balance) */

	while (curr)									/* traverse up tree */
	{
		int bf = binary_tree_balance(curr);			/* get balance factor */

		if (bf > 1 && value < curr->left->n)		/* left heavy */
			pivot = binary_tree_rotate_right(curr);
		else if (bf < -1 && value > curr->right->n)	/* right heavy */
			pivot = binary_tree_rotate_left(curr);
		else if (bf > 1 && value > curr->left->n)	/* left-right case */
		{
			binary_tree_rotate_left(curr->left);
			pivot = binary_tree_rotate_right(curr);
		}
		else if (bf < -1 && value < curr->right->n)	/* right-left case */
		{
			binary_tree_rotate_right(curr->right);	/* rotate right child */
			pivot = binary_tree_rotate_left(curr);	/* rotate current node */
		}
		else										/* no rebalancing */
			pivot = curr;

		if (!pivot->parent)			/* if pivot is root, update tree ptr */
			*tree = pivot;

		curr = pivot->parent;						/* move up to parent */
	}
}

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree:		double pointer to root node of the AVL tree
 * @value:		value to insert
 *
 * Return:		pointer to the created node, or NULL on failure/duplicate
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *parent = NULL, *curr, *new;			/* pointers for traversal */

	if (!tree)									/* check for NULL tree ptr */
		return (NULL);
	if (!*tree)									/* if empty, create root */
		return (*tree = binary_tree_node(NULL, value));

	for (curr = *tree; curr;)			/* traverse to find insertion point */
	{
		parent = curr;
		if (value < curr->n)			/* go left or right based on value */
			curr = curr->left;
		else if (value > curr->n)		/* go right if value is greater */
			curr = curr->right;
		else							/* duplicate */
			return (NULL);

	new = binary_tree_node(parent, value);	/* create new node with parent */
	if (!new)
		return (NULL);
	if (value < parent->n)		/* insert as L child if value is less */
		parent->left = new;
	else						/* insert as R child if value is greater */
		parent->right = new;

	rebalance_up(tree, parent, value);			/* rebalance tree */
	}

	return (new);								/* UNDER FORTY LINES */
}
