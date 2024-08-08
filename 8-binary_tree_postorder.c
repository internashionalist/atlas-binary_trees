#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a binary tree using post-order
 * @tree: pointer to the root node of traversed tree
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func) /* if there's no tree or function */
		return; /* make like a tree */