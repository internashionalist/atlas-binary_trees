#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of measured tree
 *
 * Return: balance factor of the tree, or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int Lheight = 0; /* height of left subtree */
	int Rheight = 0; /* height of right subtree */

	if (!tree) /* if no tree */
		return (0); /* no forest? */

	if (tree->left) /* if left exists */
		Lheight = binary_tree_height(tree->left) + 1; /* measure left subtree */
	if (tree->right) /* if right exists */
		Rheight = binary_tree_height(tree->right) + 1; /* measure right subtree */

	return (Lheight - Rheight); /* return balance factor */
}
