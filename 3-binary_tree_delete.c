#include "binary_trees.h"

/**
 * binary_tree_delete - deletes and frees an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: void
 */

void binary_tree_delete(binary_tree_t *tree)
{
       if (tree == NULL) /* if there's no frickin tree */
              return; /* make like a tree */

       binary_tree_delete(tree->left); /* delete left child */
       binary_tree_delete(tree->right); /* delete right child */
       free(tree); /* free the tree */
}
