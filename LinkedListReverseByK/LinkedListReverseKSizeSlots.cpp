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

void append(Node* head, int data)
{
	auto current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = newNode(data);
}

Node* reverse(Node* node, Node** head, int k, int l, Node** nextRootToRevert)
{
	if (node->next == nullptr)
	{
		*head = node;
		return node;
	}
	else if (l == 1)
	{
		*head = node;
		*nextRootToRevert = node->next;
		return node;
	}
	else
	{
		auto reversed = reverse(node->next, head, k, l -1, nextRootToRevert);
		reversed->next = node;

		if (*nextRootToRevert && k == l)
		{
			auto anyNode = (Node*)malloc(sizeof(Node));
			reverse(*nextRootToRevert, nextRootToRevert, k, k, &anyNode);
			node->next = *nextRootToRevert;

			return anyNode;
		}
		else
		{
			node->next = nullptr;
		}

		return node;
	}
}

void print(Node* current)
{
	if (current == nullptr)
	{
		std::cout << std::endl;
		return;
	}

	std::cout << current->data << " ";
	print(current->next);
}

int main(int argc, char* argv[])
{
	auto root = newNode(1);
	append(root, 2);
	append(root, 3);
	append(root, 4);
	append(root, 5);
	append(root, 6);
	append(root, 7);
	append(root, 8);
	append(root, 9);
	append(root, 10);

	print(root);

	auto anyNode = (Node*)malloc(sizeof(Node));
	reverse(root, &root, 3, 3, &anyNode);

	print(root);
}