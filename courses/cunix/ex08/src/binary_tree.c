#include "../include/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node_t *allocnode()
{
	node_t *tree = (node_t *)malloc (sizeof(node_t));
	tree->data = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

node_t *insert(node_t *root, char *key, void *data)
{
	if(root == NULL)
	{	
		root = allocnode();
		root->data = data;
		root->key = key;
		return root;
	}
	

	if(strcmp(key, (root->key)) < 0)
	{
		root->left = insert(root->left, key, data);
	}
	else
	{
		root->right = insert(root->right, key, data);
	}
	return root;
}

void print_node(node_t *node)
{
	if (node)
	{
		printf("%s %s\n", node->key, (char*) node->data);
		print_node(node->left);
		print_node(node->right);
	}
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
	if (node)
	{
		fp(node);
		print_node(node->left);
		print_node(node->right);
	}
}

void destroy_tree(node_t *node, void (*fdestroy)(node_t *root))
{
	if (node) 
	{
		destroy_tree(node->left, fdestroy);
		destroy_tree(node->right, fdestroy);
		fdestroy(node);
		free(node);
	}	
}
