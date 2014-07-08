#include <iostream>

typedef struct Node
{
	Node* left;
	Node* right;
	int data;
} Node;

int countLeafNodes(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else if (node->left == nullptr && node->right == nullptr)
	{
		return 1;
	}
	else
	{
		return countLeafNodes(node->left) + countLeafNodes(node->right);
	}
}

Node* newNode(int data)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

int main(int argc, char* argv[])
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	std::cout << "Number of leaf nodes is " << countLeafNodes(root);
}