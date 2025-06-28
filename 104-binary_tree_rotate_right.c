#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotates a binary tree node to the right
 * so that left child becomes new root of the rotated subtree
 *
 * @tree:	pointer to the root node of the subtree to rotate.
 *
 * Return:	pointer to the new root after rotation, or NULL on failure
 *			or if rotation is not possible
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *parent;	/* new root, new L child */

	if (!tree || !tree->left)		/* NULL || L child check */
		return (tree);

	pivot = tree->left;				/* pivot (y) -> new root */
	tree->left = pivot->right;		/* y's R subtree -> x's L child */

	if (pivot->right)				/* IF y has R child */
		pivot->right->parent = tree; /* update its parent */

	pivot->right = tree;			/* x -> R child of y */

	parent = tree->parent;			/* save x's parent */
	pivot->parent = parent;			/* set y's parent to x's parent */
	tree->parent = pivot;			/* set x's parent to y */

	if (parent)						/* if x has parent */
	{
		if (parent->left == tree)	/* if x is L child of parent */
			parent->left = pivot;	/* set y in its place */
		else
			parent->right = pivot;	/* otherwise set y as R child */
	}

	return (pivot);					/* return new root (y) */
}
