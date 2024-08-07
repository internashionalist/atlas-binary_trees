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

