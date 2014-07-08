#include <exception>
#include <iostream>

typedef struct LinkedListNode
{
	LinkedListNode* next;
	int data;

}LinkedListNode;

typedef struct LinkedList
{
	LinkedListNode** head;
}LinkedList;

int middle(LinkedList* linkedList)
{
	int count = 0;

	LinkedListNode* current = (*linkedList->head);

	LinkedListNode* middle = current;

	while (current != nullptr)
	{
		++count;

		if (count > 2 && count % 2 == 0)
		{
			middle = middle->next;
		}

		current = current->next;
	}

	if (count == 0)
	{
		throw std::exception("empty linked list");
	}

	return middle->data;
}

void initializeLinkedList(LinkedList* list)
{
	list->head = (LinkedListNode**)malloc(sizeof(LinkedListNode*));
	*list->head = nullptr;
}

LinkedListNode* newNode(int data)
{
	LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	node->data = data;
	node->next = nullptr;

	return node;
}

int main(int argc, char* argv[])
{
	LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));

	initializeLinkedList(list);

	LinkedListNode* node1 = newNode(1);
	LinkedListNode* node2 = newNode(2);
	LinkedListNode* node3 = newNode(3);
	LinkedListNode* node4 = newNode(4);
	LinkedListNode* node5 = newNode(5);
	LinkedListNode* node6 = newNode(6);
	LinkedListNode* node7 = newNode(7);
	LinkedListNode* node8 = newNode(8);
	LinkedListNode* node9 = newNode(9);
	LinkedListNode* node10 = newNode(10);
	LinkedListNode* node11 = newNode(11);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = node8;
	node8->next = node9;
	node9->next = node10;
	node10->next = node11;

	*list->head = node1;

	std::cout << middle(list) << std::endl;
}