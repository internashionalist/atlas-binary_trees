#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if node is a root
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a root, 0 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node) /* if there's no node */
		return (0); /* make like a tree */
	if (!node->parent) /* if node has no parent */
		return (1); /* it's Batman! I mean a root! */
	return (0); /* if node is not a root, return 0 */
}
