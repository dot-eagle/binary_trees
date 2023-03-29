
#include <stdlib.h>

#include "binary_trees.h"

/**
 * binary_tree_insert_left - creates & inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree = NULL;

	if (parent == NULL)
		return (NULL);

	binary_tree = calloc(1, sizeof(binary_tree_t));

	if (binary_tree == NULL)
		return (NULL);

	binary_tree->parent = parent;
	binary_tree->n = value;

	if (parent->left != NULL)
	{
		binary_tree->left = parent->left;
		binary_tree->left->parent = binary_tree;
	}
	parent->left = binary_tree;

	return (binary_tree);
}
