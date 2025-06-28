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
 * process_child - handle a child during completeness BFS
 * @child:			child node pointer
 * @queue:			current queue pointer
 * @capacity:		pointer to queue capacity
 * @rear:			pointer to rear index
 * @found_null:		pointer to NULL found flag
 * @status:			pointer to success flag (set to 0 on failure)
 *
 * Return:			updated queue pointer on success, NULL on failure
 */
const binary_tree_t **process_child(const binary_tree_t *child,
	const binary_tree_t **queue, size_t *capacity, size_t *rear,
	int *found_null, int *status)
{
	if (child)
	{
		if (*found_null)
		{
			*status = 0;
			return (queue);
		}
		queue = binary_tree_enqueue(queue, capacity, rear, child);
		if (!queue)
		{
			*status = 0;
			return (NULL);
		}
	}
	else
		*found_null = 1;
	*status = 1;
	return (queue);
}

/**
 * binary_tree_traversal - breadth‑first traversal to verify completeness
 * @root: pointer to root node
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_traversal(const binary_tree_t *root)
{
	size_t capacity = 1, front = 0, rear = 0;	/* queue capacity, indices */
	const binary_tree_t **queue;				/* ptr to queue array */
	int found_null = 0;							/* flag for NULL node found */

	/* allocate initial queue */
	queue = malloc(sizeof(*queue) * capacity);
	if (!queue)
		return (0);
	/* init queue to root */
	queue[rear++] = root;
	/* main traversal loop */
	while (front < rear)
	{
		const binary_tree_t *node;			/* node to process */
		int ok;								/* status flag for processing */

		/* get next node */
		node = queue[front++];
		/* process left child */
		queue = process_child(
			node->left, queue, &capacity, &rear, &found_null, &ok);
		if (!ok)
		{
			free(queue);
			return (0);
		}
		/* process right child */
		queue = process_child(
			node->right, queue, &capacity, &rear, &found_null, &ok);
		if (!ok)
		{
			free(queue);
			return (0);
		}
	}
	free(queue);
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
