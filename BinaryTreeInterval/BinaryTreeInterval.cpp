#include <iostream>

typedef struct Interval
{
	int low, high;
}Interval;

typedef struct Node
{
	Interval* interval;
	Node* left;
	Node* right;
	int max;
}Node;

Node * newNode(Interval interval)
{
	Node *temp = new Node;
	temp->interval = new Interval(interval);
	temp->max = interval.high;
	temp->left = temp->right = nullptr;

	return temp;
}

bool doOverlap(Interval i1, Interval i2)
{
	if (i1.low <= i2.high && i1.high >= i2.low)
	{
		return true;
	}
	
	return false;
}

Interval* intervalSearch(Node* root, Interval interval)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (doOverlap(*root->interval, interval))
	{
		return root->interval;
	}

	if (root->left != nullptr && root->left->max >= interval.low)
	{
		intervalSearch(root->left, interval);
	}
	else
	{
		intervalSearch(root->right, interval);
	}

}

Node* insert(Node* root, Interval interval)
{
	if (root == nullptr)
	{
		return newNode(interval);
	}

	int rootLowValue = root->interval->low;

	if (interval.low < rootLowValue)
	{ 
		root->left = insert(root->left, interval);
	}
	else
	{
		root->right = insert(root->right, interval);
	}

	if (root->max < interval.high)
	{
		root->max = interval.high;
	}

	return root;
}


void inorder(Node *root)
{
	if (root == nullptr)
	{
		return;
	}

	inorder(root->left);

	std::cout << "[" << root->interval->low << ", " << root->interval->high << "]" << " max = " << root->max << std::endl;

	inorder(root->right);
}


int main()
{
	Interval ints[] = { { 15, 20 }, { 10, 30 }, { 17, 19 }, { 5, 20 }, { 12, 15 }, { 30, 40 } };
	int n = sizeof(ints) / sizeof(ints[0]);
	Node *root = NULL;
	for (int i = 0; i < n; i++)
	{
		root = insert(root, ints[i]);
	}

	std::cout << "Inorder traversal of constructed Interval Tree is\n";
	inorder(root);

	Interval x = { 6, 7 };

	std::cout << "\nSearching for interval [" << x.low << "," << x.high << "]";
	Interval *res = intervalSearch(root, x);
	if (res == NULL)
	{
		std::cout << "\nNo Overlapping Interval";
	}
	else
	{
		std::cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";
	}
}
