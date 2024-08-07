#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node
 * @value: value inside the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node; /* create a new node */
	
	new_node = malloc(sizeof(binary_tree_t)); /* malloc for new node */
	if (!new_node) /* if malloc fails */
		return (NULL); /* return NULL */

	new_node->n = value; /* set value of new node */
	new_node->parent = parent; /* set parent of new node */
	new_node->left = NULL; /* set left child of new node to NULL */
	new_node->right = NULL; /* set right child of new node to NULL */

	return (new_node); /* return pointer to new node */
}
