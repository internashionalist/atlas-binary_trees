#include "binary_trees.h"
#include "15-binary_tree_is_full.c"
#include "14-binary_tree_balance.c"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the potentially perfect tree
 *
 * Return: 1 if perfect, 0 if garbage
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree) /* if no tree */
		return (0); /* def not perfect */

	if (!tree->left && !tree->right) /* if tree is just a root */
		return (1); /* it's technically perfect */
	/* if full and balanced */
	if (binary_tree_is_full(tree) && binary_tree_balance(tree) == 0)
	{	/* if both subtrees are perfect */
		if (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
			return (1); /* it's a perfect little tree */
	}
	return (0); /* otherwise, it's garbage */
}
