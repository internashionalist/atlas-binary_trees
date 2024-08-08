#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses a binary tree using pre-order
 * @tree: pointer to the root node of traversed tree
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func) /* if there's no tree or function */
		return; /* make like a tree */

	func(tree->n); /* call function on root */
	binary_tree_preorder(tree->left, func); /* traverse left subtree */
	binary_tree_preorder(tree->right, func); /* traverse right subtree */
}
