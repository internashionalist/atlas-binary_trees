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
	size_t capacity = 1, front = 0, rear = 0;	/* queue indices & size */
	const binary_tree_t **queue;				/* queue for traversal */
	int found_null = 0;							/* flag for null nodes */

	/* NULL tree check */
	if (!tree)
		return (0);

	/* allocate initial queue - it'll grow */
	queue = malloc(sizeof(*queue) * capacity);
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
			if (rear == capacity)
			{
				/* double queue size when full */
				capacity *= 2;
				queue = realloc(queue, sizeof(*queue) * capacity);
				if (!queue)
					return (0);
			}
			/* add left child to queue & increment rear index */
			queue[rear++] = node->left;
		}

		/* if no left child, fly flag */
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
			if (rear == capacity)
			{
				/* same here - double queue size when full */
				capacity *= 2;
				queue = realloc(queue, sizeof(*queue) * capacity);
				if (!queue)
					return (0);
			}
			/* add right child to queue & increment rear index */
			queue[rear++] = node->right;
		}

		/* if no right child, fly flag */
		else
		{
			found_null = 1;
		}
	}

	/* no null nodes found */
	free(queue);
	return (1);
}
