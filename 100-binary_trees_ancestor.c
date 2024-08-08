#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the LCA of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the LCA node, or NULL if no ancestor
 * 	or if first or second are NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	if (!first || !second) /* if no first or second node */
		return (NULL); /* no ancestor */

	if (first == second) /* if first and second are same node */
		return ((binary_tree_t *)first); /* return that node */
