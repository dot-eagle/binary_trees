#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 0, If tree is NULL, else
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned int i = 0;
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);
	return (check(tree, i, size));
}

/**
 * check - helper func for binary_tree_is_complete
 * @tree: pointer to the root node of tree
 * @index: current node
 * @size: size
 *
 * Return: 1, If tree is NULL, else
 */

int check(const binary_tree_t *tree, unsigned int index, size_t size)
{
	int isComplete = 0;

	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	isComplete = check(tree->left, 2 * index + 1, size) &&
		check(tree->right, 2 * index + 2, size);
	return (isComplete);
}

/**
 * binary_tree_size - measure the size
 * @tree: pointer to the input tree
 *
 * Return: 0 if tree is NULL, else size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int size;

	if (tree == NULL)
		return (0);

	size = 1 + binary_tree_size(tree->right) + binary_tree_size(tree->left);

	return (size);
}
