#include <iostream>
#include <unordered_map>

typedef struct Node
{
	Node* next;
	int data;
}Node;

Node* newNode(int data)
{
	auto node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = nullptr;

	return node;
}

void append(Node* root, Node* nodeToAppend)
{
	if (root->next == nullptr)
	{
		root->next = nodeToAppend;
		return;
	}

	append(root->next, nodeToAppend);
}

void print(Node* current)
{
	if (current == nullptr)
	{
		return;
	}

	std::cout << current->data << " ";
	print(current->next);
}

void swapKthElement(Node** root, int k)
{
	int count = 0;

	auto current = *root;

	Node* previousK = nullptr;
	Node* previousN_K = current;

	while (current)
	{
		if (count == k - 2)
		{
			previousK = current;
		}
		if (count > k)
		{
			previousN_K = previousN_K->next;
		}

		++count;
		current = current->next;
	}

	if (previousK != nullptr && previousN_K != nullptr && previousK->next != nullptr && previousN_K->next != nullptr)
	{
		auto k = previousK->next;
		auto n_k = previousN_K->next;

		auto nextk = k->next;
		auto nextN_K = n_k->next;

		previousK->next = n_k;
		n_k->next = nextk;

		previousN_K->next = k;
		k->next = nextN_K;
	}
	else if (k == 1 && previousN_K != nullptr && previousN_K->next != nullptr)
	{
		auto k = *root;
		auto n_k = previousN_K->next;

		auto nextk = k->next;
		auto nextN_K = n_k->next;

		*root = n_k;
		n_k->next = nextk;

		previousN_K->next = k;
		k->next = nextN_K;
	}
}

int main(int argc, char* argv[])
{
	auto l1 = newNode(1);
	append(l1, newNode(2));
	append(l1, newNode(3));
	append(l1, newNode(4));
	append(l1, newNode(5));
	append(l1, newNode(6));
	append(l1, newNode(7));
	append(l1, newNode(8));
	append(l1, newNode(9));
	append(l1, newNode(10));

	swapKthElement(&l1, 1);

	print(l1);
}