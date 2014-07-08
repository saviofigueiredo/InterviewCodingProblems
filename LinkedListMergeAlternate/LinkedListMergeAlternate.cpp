#include <iostream>

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

void merge(Node** l1, Node* l2)
{
	Node* n1 = *l1;
	Node* n2 = l2;

	if (n1 != nullptr)
	{
		n1 = n1->next;
	}
	else if (l2 != nullptr)
	{
		*l1 = n2;
		n2 = n2->next;
	}

	auto l = *l1;

	for (auto i = 0; n1 != nullptr && n2 != nullptr; ++i)
	{
		if (i % 2 == 0)
		{
			l->next = n2;
			n2 = n2->next;
			l = l->next;
		}
		else
		{
			l->next = n1;
			n1 = n1->next;
			l = l->next;
		}
	}

	while (n1 != nullptr)
	{
		l->next = n1;
		n1 = n1->next;
		l = l->next;
	}
	
	while (n2 != nullptr)
	{
		l->next = n2;
		n2 = n2->next;
		l = l->next;
	}
}

int main(int argc, char* argv[])
{
	auto l1 = newNode(1);
	append(l1, newNode(3));
	append(l1, newNode(5));
	append(l1, newNode(7));
	append(l1, newNode(9));
	append(l1, newNode(11));

	auto l2 = newNode(2);
	append(l2, newNode(4));
	append(l2, newNode(6));
	append(l2, newNode(8));
	append(l2, newNode(10));
	append(l2, newNode(12));

	merge(&l1, l2);

	print(l1);
}