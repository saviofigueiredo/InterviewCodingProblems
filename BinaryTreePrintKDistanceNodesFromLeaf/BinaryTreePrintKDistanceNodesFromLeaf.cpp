#include <iostream>
#include <algorithm>

typedef struct Node
{
	Node* left;
	Node* right;
	int data;
};

int printKDistancesFromLeaf(Node* root, int k)
{
	if (root == nullptr)
	{
		return -1;
	}

	if (root->left == nullptr && root->right == nullptr	)
	{
		return 0;
	}

	int distanceLeft = printKDistancesFromLeaf(root->left, k);

	if (distanceLeft != -1)
	{
		if (distanceLeft + 1 == k)
		{
			std::cout << root->data << std::endl;
		}

		distanceLeft += 1;
	}

	int distanceRight = printKDistancesFromLeaf(root->right, k);
	if (distanceRight != -1)
	{
		if (distanceRight + 1 == k)
		{
			std::cout << root->data << std::endl;
		}

		distanceRight += 1;
	}

	if (distanceRight != -1 && distanceLeft != -1)
	{
		return std::max(distanceLeft, distanceRight);
	}
	else if (distanceRight != -1)
	{
		return distanceRight;
	}
	else if (distanceLeft != -1)
	{
		return distanceLeft;
	}
	else
	{
		return -1;
	}
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
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
	printKDistancesFromLeaf(root, 2);

	return EXIT_SUCCESS;
}
