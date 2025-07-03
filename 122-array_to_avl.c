#include "binary_trees.h"

/**
 * array_to_avl - converts an array to an AVL tree
 * @array:		pointer to first element of the array
 * @size:		number of elements in the array
 *
 * Return:		pointer to the root of the created AVL tree or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;											/* loop index */
	avl_t *root = NULL;									/* init root */

	if (!array || size == 0)							/* NULL/empty check */
		return (NULL);

	for (i = 0; i < size; i++)							/* array loop */
	{
		if (!root)										/* if NULL root */
		{
			root = binary_tree_node(NULL, array[i]);	/* create root node */
			if (!root)
				return (NULL);
		}
		else											/* if root exists */
		{
			avl_t *node;								/* new node pointer */

			node = binary_tree_node(NULL, array[i]);	/* create new node */
			if (!node)
				return (NULL);
		}
	}
	return (root);
}