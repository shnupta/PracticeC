// bst.c
// The source file for binary search tree implentation
// Author: Casey Williams


#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

bst_node* create_node(int value)
{
	bst_node* node = malloc(sizeof(bst_node));
	node->value = value;
	node->left = 0;
	node->right = 0;

	return node;
}

bst_node* insert(bst_node* root, int value)
{
	if(root == 0) root = create_node(value);
	else if(value < root->value) root->left = insert(root->left, value);
	else if(value > root->value) root->right = insert(root->right, value);

	return root;
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


int is_in_tree(bst_node* root, int value)
{
	if (root == 0) return 0;
	if(root->value == value) return 1;
	else if(value < root->value) return is_in_tree(root->left, value);
	else if(value > root->value) return is_in_tree(root->right, value);
}


int get_height(bst_node* root)
{
	if(root == 0) return 0;
	return 1 + max(get_height(root->left), get_height(root->right));
}

int max(int val1, int val2)
{
	if (val1 > val2) return val1;
	else if(val2 > val1) return val2;
	else return val1;
}

int get_min(bst_node* root)
{
	if(root == 0) return -1;
	while(root->left != 0) root = root->left;
	return root->value;
}

int get_max(bst_node* root)
{
	if(root == 0) return -1;
	while(root->left != 0) root = root->left;
	return root->value;
}

int is_binary_search_tree(bst_node* root)
{
	if(root == 0) return 1;
	int temp;
	if (root->left->value < root->value && root->value < root->right->value) temp = 1;
	else temp = 0;

	return (temp && is_binary_search_tree(root->left) && is_binary_search_tree(root->right));
}

void delete_value(bst_node* root, int value)
{
	if(root == 0) return;

	if(value < root->value) return delete_value(root->left, value);
	else if(value > root->value) return delete_value(root->right, value);
	else
	{
	
		if(root->left == 0 && root->right == 0) free(root);	
		else if(root->left == 0)
		{
			// this node has a right sub-tree
			*root = *root->right;
		}
	}
	
}
