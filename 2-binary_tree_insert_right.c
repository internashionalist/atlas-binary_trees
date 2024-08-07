#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node; /* create a new node */

	if (!parent) /* if there is no parent */
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t)); /* malloc for new node */
	if (!new_node) /* if malloc fails */
		return (NULL);

	new_node->n = value; /* set value of new node */
	new_node->parent = parent; /* set parent of new node */
	new_node->right = parent->right; /* turns out it IS necessary */
	new_node->left = NULL; /* set left child of new node to NULL */

	if (parent->right) /* if parent's right child already exists */
		parent->right->parent = new_node; /* set parent of parent's right child */

	parent->right = new_node; /* insert new node as parent's right child */

	return (new_node); /* return pointer to new node */
}
