#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_levelorder - traverses a binary tree using level-order
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree); /* get height of tree */
	int i; /* counter */

	if (!tree || !func) /* if no tree or no function */
		return; /* GTFO */

	for (i = 1; i <= height + 1; i++) /* for each level */
		binary_tree_levelorder_helper(tree, i, func); /* call helper */
}


/**
 * binary_tree_levelorder_helper - helper function for level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @level: level of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_levelorder_helper(const binary_tree_t *tree,
					int level, void (*func)(int))
{
	if (!tree) /* if no tree */
		return; /* GTFO */

	if (level == 1) /* if at the level we want */
		func(tree->n); /* call the function */

	else if (level > 1) /* if not at the level we want */
	{
		binary_tree_levelorder_helper(tree->left, level - 1, func); /* go left */
		binary_tree_levelorder_helper(tree->right, level - 1, func); /* go right */
	}
}
