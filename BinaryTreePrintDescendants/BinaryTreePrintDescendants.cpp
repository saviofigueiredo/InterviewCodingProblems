#include <iostream>
#include <stack>
#include <algorithm>
typedef struct Node
{
	Node* left;
	Node* right;
	int data;
}Node;

void printDescendants(Node *root, int data, bool print)
{
	if (root == nullptr)
	{
		return;
	}
	
	if (print == true)
	{
		std::cout << root->data << std::endl;
	}

	if (print == false && root->data == data)
	{
		print = true;
	}

	printDescendants(root->left, data, print);
	printDescendants(root->right, data, print);
}

void printDescendants(Node* root, int data)
{
	bool elementFound = false;

	std::stack<Node*> nodesToVisit;

	nodesToVisit.push(root);

	while (nodesToVisit.empty() == false)
	{
		Node* current = nodesToVisit.top();
		nodesToVisit.pop();

		if (current->data == data)
		{
			while (nodesToVisit.empty() == false)
			{
				nodesToVisit.pop();
			}

			elementFound = true;
		}
		else if (elementFound == true)
		{
			std::cout << current->data << std::endl;
		}

		if (current->left != nullptr)
		{
			nodesToVisit.push(current->left);
		}
		if (current->right != nullptr)
		{
			nodesToVisit.push(current->right);
		}
	}
}

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
	else if (printAncestors(root->left, data) || printAncestors(root->right, data))
	{
		std::cout << root->data << std::endl;
		return true;
	}

	return false;
}

int numberOfDescendants(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int n = 0;

	if (root->left != nullptr)
	{
		n += 1 + numberOfDescendants(root->left);
	}

	if (root->right != nullptr)
	{
		n += 1 + numberOfDescendants(root->right);
	}

	return n;
}

int numberOfDescendants(Node* node, int data)
{
	std::stack<Node*> nodes;

	nodes.push(node);

	bool elementFound = false;

	int count = 0;

	while (nodes.empty() == false)
	{
		auto currentNode = nodes.top();
		nodes.pop();

		if (elementFound == true)
		{
			count++;
		}
		else if (currentNode->data == data)
		{
			elementFound = true;

			while (nodes.empty() == false)
			{
				nodes.pop();
			}
		}

		if (currentNode->left != nullptr)
		{
			nodes.push(currentNode->left);
		}
		if (currentNode->right != nullptr)
		{
			nodes.push(currentNode->right);
		}
	}

	return count;
}

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = nullptr;
	return (node);
}

int printKDistancesFromLeaf(Node* root, int k)
{
	if (root == nullptr)
	{
		return -1;
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		return 0;
	}

	int leftDistance = printKDistancesFromLeaf(root->left, k);

	if (leftDistance != -1)
	{
		if (leftDistance + 1 == k)
		{
			std::cout << root->data << std::endl;
		}

		leftDistance += 1;
	}

	int rightDistance = printKDistancesFromLeaf(root->right, k);
	if (rightDistance != -1)
	{
		if (rightDistance + 1 == k)
		{
			std::cout << root->data << std::endl;
		}
		rightDistance += 1;
	}

	return std::max(leftDistance, rightDistance);
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

	std::cout << "Descendants of node 2 are: " << std::endl;
	printDescendants(root, 2, false);

	std::cout << "Ancestors of node 8 are: " << std::endl;
	printAncestors(root, 8);

	std::cout << "Number of descendantes of root are: " << std::endl;
	std::cout << numberOfDescendants(root);

	std::cout << "Number of descendantes of node 2 is: " << std::endl;
	std::cout << numberOfDescendants(root, 2);

	std::cout << "Number of nodes at distance 1 from leaf are: " << std::endl;
	printKDistancesFromLeaf(root, 1);

	return EXIT_SUCCESS;
}