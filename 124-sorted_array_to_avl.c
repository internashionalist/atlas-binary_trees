#include "binary_trees.h"

/**
 * build_avl - recursively build AVL subtree from a sorted sub‑array
 * @arr:		pointer to the full (sorted) int array
 * @lo:			lowest index (inclusive)
 * @hi:			highest index (inclusive)
 * @parent:		pointer to parent node of the subtree
 *
 * Return:		pointer to root of created subtree (or NULL on failure)
 */
avl_t *build_avl(int *arr, int lo, int hi, avl_t *parent)
{
	int mid;							/* middle index */
	avl_t *root;						/* root of subtree */

	/* empty sub-array (base case) */
	if (lo > hi)
		return (NULL);

	/* find middle index (to create a balanced node) */
	mid = (lo + hi) / 2;

	/* create new node with middle element of sub-array */
	root = binary_tree_node(parent, arr[mid]);

	if (!root)
		return (NULL);

	/* build left and right subtrees */
	root->left  = build_avl(arr, lo, mid - 1, root);
	root->right = build_avl(arr, mid + 1, hi, root);

	/* return root to created subtree */
	return (root);
}

/**
 * sorted_array_to_avl - convert a sorted array to an AVL tree
 * @array:		pointer to first element of the sorted array
 * @size:		number of elements in the array
 *
 * Return:		pointer to root of the created AVL tree (or NULL on failure)
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	/* check for empty array */
	if (!array || size == 0)
		return (NULL);

	/* build AVL tree from the sorted array */
	return (build_avl(array, 0, (int)size - 1, NULL));
}
