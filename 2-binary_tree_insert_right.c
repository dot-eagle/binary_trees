#include "binary_trees.h"

/**
 * binary_tree_insert_right - creates a node in binary tree at insert in right
 * @parent: binary tree
 * @value: value
 * Return: new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree = NULL;

	if (parent == NULL)
		return (NULL);

	binary_tree = calloc(1, sizeof(binary_tree_t));

	if (binary_tree == NULL)
		return (NULL);

	binary_tree->parent = parent;
	binary_tree->n = value;

	if (parent->right != NULL)
	{
		binary_tree->right = parent->right;
		binary_tree->right->parent = binary_tree;
	}
	parent->right = binary_tree;

	return (binary_tree);
}
