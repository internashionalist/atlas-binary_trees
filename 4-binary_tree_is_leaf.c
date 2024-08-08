#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node) /* if there's no node */
		return (0); /* make like a tree */
	if ((!node->left) && (!node->right)) /* if node has no children */
		return (1); /* it's a leaf! */
	return (0); /* if node is not a leaf, return 0 */
}
