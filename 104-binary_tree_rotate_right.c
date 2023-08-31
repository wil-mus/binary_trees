#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  rotation on a tree
 * @tree: Pointer to
 *
 * Return: Pointer
 *
 * FUNCTIONALITY *
 *
 * 1. Check if the tree is NULL or if the tree’s left child is NULL.
 * If either is true, return NULL.
 *
 * 2. Set the parent to the tree and the child to the tree’s left child.
 *
 * 3. If the child’s right child is not NULL,
 * set the child’s right child’s parent to the parent.
 *
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *chl, *parent = tree;

	if (!tree)
		return (NULL);

	chl = parent->left;
	if (!chl)
		return (tree);

	if (chl->right)
		chl->right->parent = parent;

	parent->left = chl->right;
	chl->right = parent;
	chl->parent = parent->parent;
	parent->parent = chl;

	if (chl->parent && chl->parent->left == parent)
		chl->parent->left = chl;
	else if (chl->parent)
		chl->parent->right = chl;

	return (chl);
}
