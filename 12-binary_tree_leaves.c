#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the counted tree
 *
 * Return: number of leaves, or 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0; /* initialize leaf counter */

	if (!tree) /* if no tree */
		return (0); /* no leaves */
	if (!tree->left && !tree->right) /* if no children */
		return (1); /* that's a leaf! */
	leaves = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
	/* add leaves in both subtrees */
	return (leaves); /* return total number of leaves */
}
