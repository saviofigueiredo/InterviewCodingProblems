#include <iostream>

typedef struct TreeNode
{
	int data;

	TreeNode* left;
	TreeNode *right;
}TreeNode;

TreeNode* lowestCommonAncestor(TreeNode* root, int n1, int n2)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->data > n1 && root->data > n2)
	{
		return lowestCommonAncestor(root->left, n1, n2);
	}
	else if (root->data < n1 && root->data < n2)
	{
		return lowestCommonAncestor(root->right, n1, n2);
	}

	return root;
}

TreeNode* newNode(int data)
{
	auto node = (TreeNode*)malloc(sizeof(TreeNode));

	node->data = data;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

/*
                       20
			      8         22
				4   12       
                   10 14
*/

int main(int argc, char* argv[])
{
	auto root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	auto n1 = 10, n2 = 14;
	auto t = lowestCommonAncestor(root, n1, n2);
	std::cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << std::endl;

	n1 = 14, n2 = 8;
	t = lowestCommonAncestor(root, n1, n2);
	std::cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << std::endl;

	n1 = 10, n2 = 22;
	t = lowestCommonAncestor(root, n1, n2);
	std::cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << std::endl;

	return EXIT_SUCCESS;
}