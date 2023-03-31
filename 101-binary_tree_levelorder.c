#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes thru a binary tree using level-ordr traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void, if tree or func is NULL
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, height;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 0; i <= height; i++)
		print_tree(tree, func, i);
}
/**
 * print_tree - prints
 * @tree: pointer to the root node of tree
 * @func: pointer to the function to call
 * @level: depth
 */
void print_tree(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 0)
		func(tree->n);
	else
	{
		print_tree(tree->left, func, level - 1);
		print_tree(tree->right, func, level - 1);
	}
}
/**
 * binary_tree_height - height of a binary tree
 * @tree: pointer to input tree
 * Return: 0, if tree is NULL, else height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (measure(tree) - 1);
}
/**
 * measure - helper
 * @tree: pointer to input tree
 * Return: 0 if tree is NULL else height of tree
 */
size_t measure(const binary_tree_t *tree)
{
	size_t left, right;
	int total;

	if (tree == NULL)
		return (0);

	left = measure(tree->left);
	right = measure(tree->right);
	total = max(left, right) + 1;
	return (total);
}

/**
 * max - helper
 * @a: the first number
 * @b: the second number
 * Return: height of tree
 */
int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
