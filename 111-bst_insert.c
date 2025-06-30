#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree (BST)
 * @tree:		Double pointer to root node of the BST.
 * @value:		value to insert
 *
 * Return:		pointer to newly created node, NULL on failure or if value
 *				already exists in the tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL, *current, *new; /* ptrs for traversal, new node */

	if (!tree)
		return (NULL);

	/* if empty tree -> create root */
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	/* start at root */
	current = *tree;

	/* find spot for new node */
	while (current)
	{
		parent = current;
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else							/* value already exists */
			return (NULL);
	}

	/* create the new node */
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	/* insert the new node */
	if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;

	/* return the new node */
	return (new);
}
