#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
       binary_tree_t *new_node; /* create a new node */

       if (!parent) /* if there is no parent */
              return (NULL); /* return NULL */

       new_node = malloc(sizeof(binary_tree_t)); /* malloc for new node */
       if (!new_node) /* if malloc fails */
              return (NULL); /* return NULL */

       new_node->n = value; /* set value of new node */
       new_node->parent = parent; /* set parent of new node */
       new_node->left = parent->left; /* IS THIS NECESSARY? */
       new_node->right = NULL; /* set right child of new node to NULL */


