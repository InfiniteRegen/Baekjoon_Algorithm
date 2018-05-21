#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
}node_t;

node_t *root;

/* make root node with initial data */
void InitTree(int data)
{

	node_t *newNode;

	newNode = (node_t *)(malloc(sizeof(node_t)));
	root = newNode;
	root->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return;
}

/* attach child node with data */
node_t *AddChild(node_t *parent, int data)
{

	if ((parent->left != NULL) && (parent->right != NULL)) {
		printf("This node is already full \n");
		return NULL;
	}

	node_t *newNode;

	newNode = (node_t *)(malloc(sizeof(node_t)));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	if (parent->left == NULL) {
		parent->left = newNode;
	}
	else if (parent->right == NULL) {
		parent->right = newNode;
	}

	return newNode;

}

/* retrieve nodes in pre-order */
void PreOrder(node_t *r)
{

	printf("%d ", r->data);

	if (r->left)
		PreOrder(r->left);
	if (r->right)
		PreOrder(r->right);

	return;
}

void FreeAllNodes(node_t *node)
{
    if (node == NULL)
        return;

    if (node->left)
        PreOrder(node->left);
    if (node->right)
        PreOrder(node->right);

    free(node);

    return;
}

int main(int argc, char** argv)
{
	InitTree(1); /* make root node with data 1 */

	node_t *left = AddChild(root, 2); /* make left-node with data 2 && attach it to root node */
	node_t *right = AddChild(root, 3); /* make right-node with data 3 && attach it to root node */

	AddChild(left, 4); /* make left-node with data 2 && attach it to root node */
	AddChild(left, 5);
	AddChild(right, 6);
	AddChild(right, 7);

    printf("========================\n");
	PreOrder(root);
    printf("\n========================\n");


    FreeAllNodes(root);
	return 0;
}
