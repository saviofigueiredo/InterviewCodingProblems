#include <iostream>
#include <limits.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

bool isValid(TreeNode* root, int leftLimit = INT_MIN, int rightLimit = INT_MAX)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->data > leftLimit && root->data < rightLimit)
	{
		return isValid(root->left, leftLimit, root->data) && isValid(root->right, root->data, rightLimit);
	}

	return false;
}


TreeNode* newNode(int data)
{
	auto node = (TreeNode*)malloc(sizeof(TreeNode));

	node->data = data;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

int main(int argc, char* argv[])
{
	auto root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(12);

	std::cout << "IsValid should return false (Tree node 12 is dupplicated): " << isValid(root) << std::endl;

	root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	std::cout << "IsValid should return true (no dupplicates): " << isValid(root) << std::endl;

	return EXIT_SUCCESS;
}