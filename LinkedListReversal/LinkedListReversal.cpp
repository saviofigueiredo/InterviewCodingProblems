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

Node* reverseRecursionTailOtimization(Node* current, Node** head, Node* previous = nullptr)
{
	auto next = current->next;
	current->next = previous;

	if (next == nullptr)
	{
		*head = current;
		return current;
	}

	current->next = previous;

	return reverseRecursionTailOtimization(next, head, current);
}

Node* reverseRecursion(Node* current, Node** head)
{
	if (current->next == nullptr)
	{
		*head = current;
		return current;
	}

	auto reversed = reverseRecursion(current->next, head);
	reversed->next = current;
	current->next = nullptr;

	return current;
}

void reverseIteratively(Node* root, Node** head)
{
	auto current = root;
	Node* previous = nullptr;

	while (current != nullptr)
	{
		Node* next = current->next;
		
		current->next = previous;
		previous = current;
		current = next;
	}

	*head = previous;
}

void print(Node* root)
{
	while (root)
	{
		std::cout << root->data << " ";
		root = root->next;
	}

	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	auto root = newNode(1);
	root->next = newNode(2);
	root->next->next = newNode(3);
	root->next->next->next = newNode(4);

	print(root);
	// reverseRecursion(root, &root);
	// reverseIteratively(root, &root);
	reverseRecursionTailOtimization(root, &root);
	print(root);
}