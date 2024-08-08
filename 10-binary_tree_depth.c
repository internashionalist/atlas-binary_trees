#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the measured node
 *
 * Return: depth of node, or 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0; /* initialize depth counter */

	if (!tree) /* if no tree */
		return (0); /* leaf.. get it? */

	while (tree->parent) /* while there are limbs above */
	{
		depth++; /* increment depth */
		tree = tree->parent; /* move up the tree */
	}

	return (depth); /* return depth of node */
}
