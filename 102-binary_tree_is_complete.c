#include "binary_trees.h"

/**
 * binary_tree_enqueue - adds a node pointer to the queue
 * @queue:		pointer to current queue array
 * @capacity:	pointer to queue's growing capacity
 * @rear:		pointer to index where next node will be added
 * @node:		node to add to the queue
 *
 * Return:		queue pointer (updated)on success, NULL on failure
 */
const binary_tree_t **binary_tree_enqueue(
	const binary_tree_t **queue, size_t *capacity,
	size_t *rear, const binary_tree_t *node)
{
	const binary_tree_t **tmp = queue; /* temp ptr for realloc */

	/* if queue is full */
	if (*rear == *capacity)
	{
		/* double the capacity */
		*capacity *= 2;

		/* reallocate memory for the queue */
		tmp = realloc(tmp, sizeof(*tmp) * (*capacity));
		if (!tmp)
			return (NULL);
	}

	/* add node to the queue */
	tmp[(*rear)++] = node;

	/* return updated queue */
	return (tmp);
}

/**
 * binary_tree_traversal - breadth‑first traversal to verify completeness
 * @root: pointer to root node
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_traversal(const binary_tree_t *root)
{
	size_t capacity = 1, front = 0, rear = 0;	/* queue indices & size */
	const binary_tree_t **queue;				/* queue for traversal */
	int found_null = 0;							/* flag for null children */

	queue = malloc(sizeof(*queue) * capacity);	/* initial allocation */
	if (!queue)
		return (0);

	queue[rear++] = root;						/* enqueue root node */

	while (front < rear)						/* main traversal loop */
	{
		const binary_tree_t *node = queue[front++]; /* get current node */

		if (node->left)							/* process left child */
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			queue = binary_tree_enqueue(queue, &capacity, &rear, node->left);
			if (!queue)
			{
				free(queue);
				return (0);
			}
		}
		else
			found_null = 1;						/* no left child */

		if (node->right)						/* process right child */
		{
			if (found_null)
			{
				free(queue);
				return (0);
			}
			queue = binary_tree_enqueue(queue, &capacity, &rear, node->right);
			if (!queue)
			{
				free(queue);
				return (0);
			}
		}
		else
			found_null = 1;						/* no right child */
	}

	free(queue);								/* no null nodes found */
	return (1);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *                           (all levels filled left‑to‑right)
 * @tree: pointer to root node of tree
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/* check for NULL tree */
	if (!tree)
		return (0);

	/* breadth‑first completeness check */
	return (binary_tree_traversal(tree));
}
