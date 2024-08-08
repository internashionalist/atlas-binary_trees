#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node whose uncle we're finding
 *
 * Return: pointer to the uncle node, or NULL if no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{	/* check if node, parent, or grandparent are NULL */
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	/* if node's parent is left child of grandparent */
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right); /* return right uncle */
	/* if node's parent is right child of grandparent */
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left); /* return left uncle */

	return (NULL); /* or return NULL if no uncle */
}
