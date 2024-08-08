#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the potentially perfect tree
 *
 * Return: 1 if perfect, 0 if garbage
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
       if (!tree) /* if no tree */
              return (0); /* def not perfect */

       if (!tree->left && !tree->right) /* if tree is just a root */
              return (1); /* it's technically perfect */