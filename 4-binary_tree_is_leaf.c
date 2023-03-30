#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 0 if node is NULL, else 1if node is a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int isALeaf;

	if (node == NULL)
		return (0);

	isALeaf = !node->left && !node->right;
	return (isALeaf);
}
