#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of tree being measured
 *
 * Return: height of tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
       size_t Lheight; /* height of left subtree */
       size_t Rheight; /* height of right subtree */

       if (tree == NULL) /* if there's no frickin tree */
              return (0); /* make like a tree */

       Lheight = 1 + binary_tree_height(tree->left); /* measure left subtree */
       Rheight = 1 + binary_tree_height(tree->right); /* measure right subtree */

       if (Lheight > Rheight) /* if left subtree is taller */
              return (Lheight); /* return height of left subtree */
       else
              return (Rheight); /* return height of right subtree */
}
