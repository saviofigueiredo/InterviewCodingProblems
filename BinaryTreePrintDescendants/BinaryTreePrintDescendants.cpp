/*
Given a Binary Tree and a key, write a function that prints all the descendants of the key in the given binary tree.

For example, if the given tree is following Binary Tree and key is 2, then your function should print 4, 5 and 7.

		1
	  /   \
     2      3
	/  \
   4    5
  /
 7

*/
#include <iostream>
#include <stack>
#include <algorithm>

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

	void printDescendants(T nodeData, bool print)
	{
		if (print == true)
		{
			std::cout << data << std::endl;
		}

		if (print == false && data == nodeData)
		{
			print = true;
		}

		if (left != nullptr)
		{
			left->printDescendants(nodeData, print);
		}
		if (right != nullptr)
		{
			right->printDescendants(nodeData, print);
		}
	}

	void printDescendants(int nodeData)
	{
		bool elementFound = false;

		std::stack<Node*> nodesToVisit;
		nodesToVisit.push(this);

		while (nodesToVisit.empty() == false)
		{
			auto current = nodesToVisit.top();
			nodesToVisit.pop();

			if (current->data == nodeData)
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

	std::cout << "Descendants of node 2 are: " << std::endl;
	root->printDescendants(2, false);

	std::cout << "Descendants of node 2 are: " << std::endl;
	root->printDescendants(2);

	return EXIT_SUCCESS;
}