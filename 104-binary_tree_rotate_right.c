#include "binary_trees.h"


/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp, *PARENT;
	int left_child;

	if (tree == NULL)
		return (NULL);

	left_child = 0;
	tmp = tree->left;
	if (tmp != NULL)
	{
		PARENT = tree->parent;
		if (PARENT != NULL)
			left_child = tree->parent->left == tree;

		tree->left = tmp->right;
		if (tmp->right)
			tmp->right->parent = tree;
		tree->parent = tmp;

		tmp->right = tree;
		tmp->parent = PARENT;
		if (PARENT != NULL)
		{
			if (left_child)
				PARENT->left = tmp;
			else
				PARENT->right = tmp;
		}
	}
	while (tree->parent)
		tree = tree->parent;

	return (tree);
}
