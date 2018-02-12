#include "bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int passed;
int total;


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

	printf("All tests complete.\n%d out of %d tests passed.", passed, total);
}

void fail()
{
	printf("FAILED\n\n");
	total++;
}

void pass()
{
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
		return fail();
	}

	delete_tree(root);
	return pass();
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

	if(root->left->value != 10) return fail();
	if(root->right->value != 17) return fail();
	if(root->left->left->value != 4) return fail();
	if(root->right->left->value != 16) return fail();
	if(root->left->right->value != 12) return fail();
	if(root->right->right->value != 22) return fail();

	delete_tree(root);

	return pass();

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

	if(get_node_count(root) != 7) return fail();

	delete_tree(root);

	return pass();
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

	if(!is_in_tree(root,10)) return fail();
	if(!is_in_tree(root,17)) return fail();
	if(!is_in_tree(root,4)) return fail();
	if(!is_in_tree(root,16)) return fail();
	if(!is_in_tree(root,12)) return fail();
	if(!is_in_tree(root,22)) return fail();

	delete_tree(root);

	return pass();
}
