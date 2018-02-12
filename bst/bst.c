// bst.c
// The source file for binary search tree implentation
// Author: Casey Williams


#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

bst_node* create_node(int value)
{
	bst_node* node = malloc(sizeof(bst_node*));
	node->value = value;
	node->left = 0;
	node->right = 0;

	return node;
}

void insert(bst_node* root, int value)
{
	if(root == 0) root->value = value;
	else if(value < root->value) insert(root->left, value);
	else if(value > root->value) insert(root->right, value);
}

int get_node_count(bst_node* root)
{
	if(root == 0) return 0;
	return 1 + get_node_count(root->left) + get_node_count(root->right);
}


void print_values(bst_node* root)
{
	if(root == 0) return;
	print_values(root->left);
	printf("%d ", root->value);
	print_values(root->right);
}


void delete_tree(bst_node* root)
{
	if(root == 0) return;
	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}
