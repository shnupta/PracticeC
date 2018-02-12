// bst.h
// The header file containing the definitions for the node structure and related functions for the binary search tree.
// Author: Casey Williams

typedef struct bst_node
{
	int value;
	struct bst_node* left;
	struct bst_node* right;
} bst_node;

bst_node* create_node(int);
void insert(bst_node*, int);
int get_node_count(bst_node*);
void print_values(bst_node*); // from min to max
void delete_tree(bst_node*);
int is_in_tree(bst_node*, int);
int get_height(bst_node*);
int get_min(bst_node*);
int get_max(bst_node*);
int is_binary_search_tree(bst_node*);
void delete_value(bst_node*, int);
int get_successor(bst_node*, int); // returns next-highest value in tree after value, -1 if none
