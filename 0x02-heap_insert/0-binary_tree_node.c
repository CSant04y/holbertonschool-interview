#include "binary_trees.h"

/**
 * binary_tree_node()
 * 
 * 
 * 
 */ 
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    /*create a pointer for the new node*/
    binary_tree_t *node;

    node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    /* Checking for failure */
    if (!node)
        return (NULL);

    /*Initilize node pointer to parent node*/

    node->parent = parent;
    /*Initilize node with given value*/
    node->n = value;
    node->left = NULL;
    node->right = NULL;

    return (node);
}