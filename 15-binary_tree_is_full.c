#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree) /* if no tree */
		return (0); /* def not full */

	if (!binary_tree_is_full(tree->left) || !binary_tree_is_full(tree->right))
		return (0); /* if either subtree is not full */

	if (!tree->left && !tree->right)
		return (1); /* if tree IS a leaf */

	return (1); /* tree is full */
}
