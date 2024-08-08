#include "binary_trees.h"

/**
 * binary_tree_size - measures size of a binary tree
 * @tree: pointer to the root node of measured tree
 *
 * Return: size of tree, or 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0; /* initialize size counter */

	if (!tree) /* if no tree */
		return (0); /* sad hippies */
