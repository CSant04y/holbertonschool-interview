#include "binary_trees.h"

/**
 * newNode - This adds a newnode to tree
 * @array: This is array
 * @mid: This is the mid point
 * @root: Thje root node
 * Return: root node
 */
avl_t *newNode(int *array, size_t mid, avl_t *root)
{
	avl_t *n_Node;

	n_Node = malloc(sizeof(avl_t));

	if (!n_Node)
		return (NULL);

	n_Node->n = array[mid];
	n_Node->parent = root;
	n_Node->left = NULL;
	n_Node->right = NULL;

	return (n_Node);
}

/**
 * buildAvlTree - Function that builds an AVL tree from an array
 * @array: This is array that is passed
 * @root: root elem
 * @start: This is the start of the array
 * @end: This is the end of the array
 * Return: This returns root
 */
avl_t *buildAvlTree(int *array, avl_t *root, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;
	avl_t *new;

	if (start > end)
	{
		return (NULL);
	}
	new = newNode(array, mid, root);
	if (mid < end)
		new->right = buildAvlTree(array, new, mid + 1, end);
	if (mid > start)
		new->left = buildAvlTree(array, new, start, mid - 1);

	return (new);
}

/**
 * sorted_array_to_avl - This goes through takes in array and size and
 * @array: This is a sorted array that is passed to be put in binary tree
 * @size: This is the number of array elements
 * Return: apex of binary tree or root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
	{
		return (NULL);
	}

	return (buildAvlTree(array, NULL, 0, size - 1));
}
