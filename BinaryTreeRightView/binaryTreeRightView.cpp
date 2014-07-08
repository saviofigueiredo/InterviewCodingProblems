#include <iostream>

typedef struct Node
{
	Node* left;
	Node* right;
	int data;
}Node;

void rightView(Node* root, int level, int* maxLevel)
{
	if (root == nullptr)
	{
		return;
	}

	if (*maxLevel < level)
	{
		std::cout << root->data << std::endl;
		*maxLevel = level;
	}

	rightView(root->right, level + 1, maxLevel);
	rightView(root->left, level + 1, maxLevel);
}

void rightView(Node* root)
{
	int maxLevel = 0;

	rightView(root, 1, &maxLevel);
}

struct Node *newNode(int item)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

int main(int argc, char* argv[])
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);

	rightView(root);

	return EXIT_SUCCESS;
}
