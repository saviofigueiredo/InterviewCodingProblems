#include <iostream>

typedef struct Node
{
	int data;
	Node* next;
}Node;

Node* merge(Node* linkedList1, Node* linkedList2)
{
	if (linkedList1 == nullptr && linkedList2 == nullptr)
	{
		return nullptr;
	}
	else if (linkedList1 == nullptr)
	{
		return linkedList2;
	}
	else if (linkedList2 == nullptr)
	{
		return linkedList1;
	}
	else if (linkedList1->data < linkedList2->data)
	{
		Node* nextLinkedList1 = linkedList1->next;
		linkedList1->next = merge(nextLinkedList1, linkedList2);
		return linkedList1;
	}
	else
	{
		Node* nextLinkedList2 = linkedList2->next;
		linkedList2->next = merge(linkedList1, nextLinkedList2);
		return linkedList2;
	}

}

Node* newNode(int data, Node* next = nullptr)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = next;
	return node;
}

Node* createLinkedList(int data[], int length, int pos = 0)
{
	if (pos == length - 1)
	{
		return newNode(data[pos]);
	}
	
	return newNode(data[pos], createLinkedList(data, length, pos + 1));
}

int main(int argc, char* argv[])
{
	int l1Array[] = { 10, 13 };
	Node* l1 = createLinkedList(l1Array, 2);

	int l2Array[] = { 11, 12 };
	Node* l2 = createLinkedList(l2Array, 2);

	Node* l3 = merge(l1, l2);

	while (l3 != nullptr)
	{
		std::cout << l3->data << std::endl;
		l3 = l3->next;
	}
}




