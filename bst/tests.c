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
	printf("Testing bst...\n");
	test_create();


	printf("All tests complete.\n%d out of %d tests passed.", passed, total);
}

void test_create()
{
	printf("Testing create_node()\n");
	bst_node* root = create_node(15);
	printf("Left: %d\nRight: %d\nValue: %d", root->left, root->right, root->value);
	if(root->left != 0 || root->right != 0 || root->value != 15)
	{
		total++;
		return;
	}

	total++;
	free(root);
}
