#include "../src/bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int passed;
int total;

void test_create();
void test_insert();
void test_get_node_count();
void test_print_values();
void test_is_in_tree();
void test_get_height();
void test_get_min();
void test_get_max();
void test_is_binary_search_tree();
void test_delete_value();
void test_get_successor();


int main()
{
	passed = 0;
	total = 0;

	printf("Testing bst...\n\n");

	test_create();
	test_insert();
	test_get_node_count();
	test_print_values();
	test_is_in_tree();
  test_get_height();
  test_get_min();
  test_get_max();
  test_is_binary_search_tree();
  test_delete_value();
  test_get_successor();

	printf("All tests complete.\n%d out of %d tests passed.\n", passed, total);
}

void fail(bst_node* root)
{
  delete_tree(root);
	printf("FAILED\n\n");
	total++;
}

void pass(bst_node* root)
{
  delete_tree(root);
	printf("passed\n\n");
	passed++;
	total++;
}

void test_create()
{
	printf("Testing create_node()\n");
	bst_node* root = create_node(15);
	if(root->left != 0 || root->right != 0 || root->value != 15)
	{
		return fail(root);
	}

	return pass(root);
}

void test_insert()
{
	printf("Testing insert()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

	if(root->left->value != 10) return fail(root);
	if(root->right->value != 17) return fail(root);
	if(root->left->left->value != 4) return fail(root);
	if(root->right->left->value != 16) return fail(root);
	if(root->left->right->value != 12) return fail(root);
	if(root->right->right->value != 22) return fail(root);

	return pass(root);

}

void test_get_node_count()
{
	printf("Testing get_node_count()\n");


	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

	if(get_node_count(root) != 7) return fail(root);


	return pass(root);
}

void test_print_values()
{
	printf("Testing print_values\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

	print_values(root);
	printf("\n\n");
}


void test_is_in_tree()
{
	printf("Testing is_in_tree()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

	if(!is_in_tree(root,10)) return fail(root);
	if(!is_in_tree(root,17)) return fail(root);
	if(!is_in_tree(root,4)) return fail(root);
	if(!is_in_tree(root,16)) return fail(root);
	if(!is_in_tree(root,12)) return fail(root);
	if(!is_in_tree(root,22)) return fail(root);


	return pass(root);
}

void test_get_height()
{
	printf("Testing get_height()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

  if(get_height(root) != 3) return fail(root);


  return pass(root);
}

void test_get_min()
{
	printf("Testing get_min()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

  if(get_min(root) != 4) return fail(root);


  return pass(root);
}

void test_get_max()
{
	printf("Testing get_max()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

  if(get_max(root) != 22) return fail(root);


  return pass(root);
}

void test_is_binary_search_tree()
{
	printf("Testing is_binary_search_tree()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);

  if(!is_binary_search_tree(root)) return fail(root);


  return pass(root);
}

void test_delete_value()
{
  printf("Testing delete_value()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);
  insert(root, 11);
  insert(root, 13);

  delete_value(root, 10);

  if(root->left->value != 11) return fail(root);

  delete_value(root,13);
  if(get_height(root) != 3) return fail(root);


  return pass(root);
}


void test_get_successor()
{
  printf("Testing get_successor()\n");

	bst_node* root = create_node(15);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	insert(root, 12);
	insert(root, 16);
	insert(root, 22);
  insert(root, 11);
  insert(root, 13);

  if(get_successor(root, 13) != 15) return fail(root);


  return pass(root);
}
