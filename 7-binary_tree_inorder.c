#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses a binary tree using in-order
 * @tree: pointer to the root node of traversed tree
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func) /* if there's no tree or function */
		return; /* make like a tree */

	binary_tree_inorder(tree->left, func); /* call function on left subtree */
	func(tree->n); /* call function on root */
	binary_tree_inorder(tree->right, func); /* do right subtree */
}
