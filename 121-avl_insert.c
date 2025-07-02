#include "binary_trees.h"

/**
 * rebalance_up - rebalance the AVL tree upwards from given node
 * @tree:		address of the root pointer (may change)
 * @node:		starting node (parent of inserted node)
 *
 * Return:		void
 */
void rebalance_up(avl_t **tree, avl_t *node)
{
	avl_t *curr = node, *pivot;							/* current node */

	while (curr)										/* go up the tree */
	{
		int bf = binary_tree_balance(curr);				/* balance factor */

		if (bf > 1)										/* left heavy */
		{
			if (binary_tree_balance(curr->left) < 0)	/* left-right case */
				binary_tree_rotate_left(curr->left);	/* rotate left */

			pivot = binary_tree_rotate_right(curr);		/* or rotate right */
		}
		else if (bf < -1)								/* right heavy */
		{
			if (binary_tree_balance(curr->right) > 0)	/* right-left case */
				binary_tree_rotate_right(curr->right);	/* rotate right */

			pivot = binary_tree_rotate_left(curr);		/* or rotate left */
		}
		else											/* else balanced */
			pivot = curr;

		if (!pivot->parent)								/* if pivot is root */
			*tree = pivot;								/* update root */

		curr = pivot->parent;							/* go up to parent */
	}
}

/**
 * avl_insert - inserts a value in an AVL tree
 * @tree:	double pointer to root node of the AVL tree
 * @value:	value to insert
 *
 * Return:	pointer to created node or NULL on failure/duplicate
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *parent = NULL, *curr, *new;					/* current node */

	if (!tree)											/* NULL tree check */
		return (NULL);

	if (!*tree)											/* if empty tree */
		return (*tree = binary_tree_node(NULL, value));	/* create root */

	for (curr = *tree; curr;)							/* traverse tree */
	{
		parent = curr;									/* set parent */
		if (value < curr->n)							/* if val < curr */
			curr = curr->left;							/* go left */
		else if (value > curr->n)						/* if val > curr */
			curr = curr->right;							/* go right */
		else											/* if equal */
			return (NULL);
	}

	new = binary_tree_node(parent, value);				/* once found place */
	if (!new)											/* failure */
		return (NULL);
	if (value < parent->n)								/* if val < parent */
		parent->left = new;								/* insert left */
	else												/* if val > parent */
		parent->right = new;							/* insert right */

	rebalance_up(tree, parent);							/* then rebalance */

	return (new);										/* fancy new node */
}
