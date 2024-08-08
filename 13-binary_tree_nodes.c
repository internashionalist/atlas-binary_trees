#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the counted tree
 *
 * Return: number of nodes with at least 1 child, or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parents = 0; /* initialize node counter */

	if (!tree || (!tree->left && !tree->right)) /* if no tree or no children */
		return (0); /* no nodes */
	parents = 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
	/* add nodes in both subtrees */
	return (parents); /* return total number of nodes with children */
}
