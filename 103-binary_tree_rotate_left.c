#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree node to the left
 * so that right child becomes new root of the rotated subtree
 *
 * @tree:	pointer to the root node of the subtree to rotate.
 *
 * Return:	pointer to the new root after rotation,
 *			or NULL on failure or if rotation is not possible
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *parent;	/* new root, new R child */

	if (!tree || !tree->right)		/* NULL || R child check */
		return (tree);

	pivot = tree->right;			/* pivot (y) becomes new root */
	tree->right = pivot->left;		/* R child -> L child of y */

	if (pivot->left)		/* IF new root has L child -> set parent */
		pivot->left->parent = tree;	/* old root (x) -> L child of y */

	pivot->left = tree;

	/* update parents */
	parent = tree->parent;
	pivot->parent = parent;
	tree->parent = pivot;

	if (parent)						/* if x has parent */
	{
		if (parent->left == tree)	/* if x is L child of parent */
			parent->left = pivot;	/* set y in its place */
		else
			parent->right = pivot;	/* otherwise set y as R child */
	}

	return (pivot);					/* return new root (y) */
}
