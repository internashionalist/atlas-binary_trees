#include "binary_trees.h"

/**
 * bst_check - recursively validate BST with min/max
 * @node:		current node to evaluate.
 * @min:		lowest value allowed
 * @max:		highest value allowed
 *
 * Return:		1 if subtree is valid BST, otherwise 0.
 */
int bst_check(const binary_tree_t *node, int min, int max)
{
	/* empty subtree is... valid.. */
	if (!node)
		return (1);

	/* check current node value against min/max */
	if (node->n <= min || node->n >= max)
		return (0);

	/* check left and right subtrees recursively */
	return (bst_check(node->left, min, node->n) &&
			bst_check(node->right, node->n, max));
}

/**
 * binary_tree_is_bst - starts BST validation
 * @tree:		pointer to the root node of the tree
 *
 * Return:		1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* NULL tree is NOT a BST */
	if (!tree)
		return (0);

	/* start check with full int range */
	return (bst_check(tree, INT_MIN, INT_MAX));
}
