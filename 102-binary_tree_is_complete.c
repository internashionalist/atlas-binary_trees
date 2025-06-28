#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete (every level
 * is filled - last might be incomplete)
 *
 * @tree: pointer to root node of tree
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, front = 0, rear = 0;	/* front and rear indices for queue */
	const binary_tree_t **queue;		/* queue for level order traversal */
	int found_null = 0;					/* flag for null nodes */

	/* NULL tree check */
	if (!tree)
		return (0);

	/* allocate enough memory for all nodes using binary_tree_size */
	size = binary_tree_size(tree);
	queue = malloc(sizeof(*queue) * size);
	if (!queue)
		return (0);

	/* init queue with root node */
	queue[rear++] = tree;

	/* level order traversal */
	while (front < rear)
	{
		const binary_tree_t *node;

		/* get current node */
		node = queue[front++];

		/* process left child */
		if (node->left)
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = node->left;
		}
		else
		{
			found_null = 1;
		}

		/* process right child */
		if (node->right)
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = node->right;
		}
		else
		{
			found_null = 1;
		}
	}

	/* no null nodes found */
	free(queue);
	return (1);
}
