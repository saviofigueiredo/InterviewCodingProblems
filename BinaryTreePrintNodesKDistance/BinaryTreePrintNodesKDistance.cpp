#include <iostream>

typedef struct Node
{
	Node* left;
	Node* right;
	int data;
}Node;

void printKDistanceMoveDown(Node* node, int k)
{
	if (node == nullptr)
	{
		return;
	}
	if (k == 0)
	{
		std::cout << node->data << std::endl;
	}
	else
	{
		printKDistanceMoveDown(node->left, k - 1);
		printKDistanceMoveDown(node->right, k - 1);
	}
}

int printKDistanceNode(Node* root, Node* target, int k)
{
	if (root == nullptr)
	{
		return -1;
	}
	if (root == target)
	{
		printKDistanceMoveDown(root, k);
		return 0;
	}

	int distanceLeftTree = printKDistanceNode(root->left, target, k);

	if (distanceLeftTree != -1)
	{
		if (distanceLeftTree + 1 == k)
		{
			std::cout << root->data << std::endl;
		}
		else
		{
			printKDistanceMoveDown(root->right, k - distanceLeftTree - 2);
		}

		return 1 + distanceLeftTree;
	}

	int distanceRightTree = printKDistanceNode(root->right, target, k);

	if (distanceRightTree != -1)
	{
		if (distanceRightTree + 1 == k)
		{
			std::cout << root->data << std::endl;
		}
		else
		{
			printKDistanceMoveDown(root->left, k - distanceRightTree - 2);
		}

		return distanceRightTree + 1;
	}

	return -1;
}

Node *newnode(int data)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = temp->right = nullptr;
	return temp;
}

int main(int argc, char* argv[])
{
	Node * root = newnode(20);

	root->left = newnode(8);
	root->right = newnode(22);
	root->left->left = newnode(4);
	root->left->right = newnode(12);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(14);
	Node * target = root->left->right;

	printKDistanceNode(root, target, 2);

	return EXIT_SUCCESS;
}
