#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node whose sibling we're finding
 *
 * Return: pointer to the sibling node, or NULL if no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
       if (!node || !node->parent) /* if no node or no parent */
              return (NULL); /* no sibling */
