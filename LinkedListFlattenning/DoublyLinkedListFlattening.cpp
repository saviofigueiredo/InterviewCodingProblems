#include <iostream>

typedef struct Node
{
	Node* next;
	Node* previous;
	Node* child;
	int data;
}Node;

typedef struct DoublyLinkedList
{
	Node** head;
}DoublyLinkedList;

void append(Node* head, Node* nodeToAppend)
{
	Node* current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = nodeToAppend;
	nodeToAppend->previous = current;
}

void flatten(DoublyLinkedList* list)
{
	Node* current = *list->head;

	while (current != nullptr)
	{
		if (current->child != nullptr)
		{
			append(current, current->child);
		}

		std::cout << current->data;

		current = current->next;
	}
}

void separateAndExplore(Node* node)
{
	Node* previous = node->previous;
	previous->next = nullptr;
	node->previous = nullptr;

	Node* current = node;

	while (current != nullptr)
	{
		if (current->child != nullptr)
		{
			separateAndExplore(current->child);
		}

		current = current->next;
	}
}

void unflatten(DoublyLinkedList *list)
{
	Node* current = *list->head;

	while (current != nullptr)
	{
		if (current->child != nullptr)
		{
			separateAndExplore(current->child);
		}

		current = current->next;
	}
}

void initialize(DoublyLinkedList* list)
{
	list->head = (Node**)malloc(sizeof(Node*));
}

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = nullptr;
	node->previous = nullptr;
	node->child = nullptr;

	return node;
}

void setNext(Node* node, Node* next)
{
	node->next = next;
	next->previous = node;
}

int main(int argc, char* argv[])
{
	DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

	initialize(list);

	Node* node1 = newNode(1);
	Node* node2 = newNode(2);
	Node* node3 = newNode(3);
	Node* node4 = newNode(4);
	Node* node5 = newNode(5);
	Node* node6 = newNode(6);
	Node* node7 = newNode(7);
	Node* node8 = newNode(8);
	Node* node9 = newNode(9);
	Node* node10 = newNode(10);
	Node* node11 = newNode(11);

	setNext(node1, node2);
	setNext(node2, node3);
	setNext(node3, node4);
	setNext(node4, node5);
	
	node2->child = node6;
	
	setNext(node6, node7);
	setNext(node7, node8);

	node4->child = node9;
	setNext(node9, node10);
	setNext(node10, node11);

	*list->head = node1;

	flatten(list);
}