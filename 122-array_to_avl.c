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
	size_t i;									/* loop index */
	avl_t *root = NULL;							/* init root of AVL */

	if (!array || size == 0)					/* NULL/empty array check */
		return (NULL);

	for (i = 0; i < size; i++)					/* iterate through the array */
	{
		if (!avl_insert(&root, array[i]) && !root)	/* insert into AVL */
			return (NULL);
	}

	return (root);								/* return root of AVL tree */
}
