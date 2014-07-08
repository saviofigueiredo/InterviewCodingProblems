#include <iostream>

typedef struct Node
{
	Node* left;
	Node* right;

	int numberChildrenLeftTree;

	int data;
}Node;

Node* find(Node* root, int rank)
{
	if (root == nullptr)
	{
		return root;
	}
	else if (root->numberChildrenLeftTree + 1 == rank)
	{
		return root;
	}
	else if (root->numberChildrenLeftTree >= rank)
	{
		return find(root->left, rank);
	}
	else
	{
		return find(root->right, rank - root->numberChildrenLeftTree - 1);
	}
}

int numberDescendants(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + numberDescendants(root->left) + numberDescendants(root->right);
	}
}

void numberLeftChildren(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	root->numberChildrenLeftTree = numberDescendants(root->left);
	
	numberLeftChildren(root->left);
	numberLeftChildren(root->right);
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = nullptr;
	return (node);
}

int main(int argc, char* argv[])
{
	// Let us create binary tree given in the above example
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	numberLeftChildren(root);

	auto answer = find(root, 5);

	return EXIT_SUCCESS;
}