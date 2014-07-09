/*
Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree.

For example, if the given tree is following Binary Tree and key is 4, then your function should print 2 and 1.

		1
	  /   \
     2     3
    /  \
   4    5
  /
 7
*/
#include <iostream>

template <typename T>
struct Node
{
	Node* left;
	Node* right;
	T data;

	Node(T newData)
	{
		data = newData;
		left = right = nullptr;
	}

	bool printAncestors(T key)
	{
		if (data == key)
		{
			return true;
		}
		if (left != nullptr && left->printAncestors(key) || right != nullptr && right->printAncestors(key))
		{
			std::cout << data << std::endl;
			return true;
		}

		return false;
	}
};

int main(int argc, char* argv[])
{
	auto root = new Node<int>(1);
	root->left = new Node<int>(2);
	root->right = new Node<int>(3);
	root->left->left = new Node<int>(4);
	root->left->right = new Node<int>(5);
	root->right->left = new Node<int>(6);
	root->right->right = new Node<int>(7);
	root->right->left->right = new Node<int>(8);

	std::cout << "Nodes at distance 7 are: " << std::endl;
	root->printAncestors(7);

	return EXIT_SUCCESS;
}