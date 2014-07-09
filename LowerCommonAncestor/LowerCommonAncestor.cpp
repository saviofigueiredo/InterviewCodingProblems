/*
Let T be a rooted tree. 
The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants 
(where we allow a node to be a descendant of itself).
Write a method that will receive two keys as parameters and should print the lowest ancestors of those keys.

For example, if the method is called passing 6 and 7, it should print 3
If the method is called passing 2 and 7, it should print 1.

		1
      /   \
     2     3
   /  \   /  \
  4    5 6    7
*/
#include <iostream>

template <typename T>
struct Node
{
	T data;

	Node* left;
	Node *right;

	Node(T newData)
	{
		data = newData;
		left = nullptr;
		right = nullptr;
	}

	Node* lowestCommonAncestor(T n1, T n2)
	{
		if (data > n1 && data > n2 && left != nullptr)
		{
			return left->lowestCommonAncestor(n1, n2);
		}
		else if (data < n1 && data < n2 && right != nullptr)
		{
			return right->lowestCommonAncestor(n1, n2);
		}

		return this;
	}
};

int main(int argc, char* argv[])
{
	auto root = new Node<int>(20);
	root->left = new Node<int>(8);
	root->right = new Node<int>(22);
	root->left->left = new Node<int>(4);
	root->left->right = new Node<int>(12);
	root->left->right->left = new Node<int>(10);
	root->left->right->right = new Node<int>(14);

	auto n1 = 10, n2 = 14;
	auto t = root->lowestCommonAncestor(n1, n2);
	std::cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << std::endl;

	n1 = 14, n2 = 8;
	t = root->lowestCommonAncestor(n1, n2);
	std::cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << std::endl;

	n1 = 10, n2 = 22;
	t = root->lowestCommonAncestor(n1, n2);
	std::cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << std::endl;

	return EXIT_SUCCESS;
}