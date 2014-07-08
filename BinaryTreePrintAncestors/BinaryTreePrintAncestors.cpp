#include <iostream>

typedef struct Node
{
	Node* left;
	Node* right;
	int data;
};

bool printAncestors(Node* root, int data)
{
	if (root == nullptr)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	if (printAncestors(root->left, data) || printAncestors(root->right, data))
	{
		std::cout << root->data << std::endl;
		return true;
	}
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

	std::cout << "Nodes at distance 2 are: " << std::endl;
	printAncestors(root, 7);

	return EXIT_SUCCESS;
}