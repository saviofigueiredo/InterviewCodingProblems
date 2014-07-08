#include <iostream>

template <typename T>
struct Node
{
	T value;
	struct Node* next;
};

template <typename T>
struct List
{
	Node<T>* head;

	void bubbleSort()
	{
		Node<T>* previousNode = nullptr;
		bool swapped = true;

		while (swapped == true)
		{
			swapped = false;

			previousNode = nullptr;

			for (auto nodeI = head; nodeI->next != nullptr; nodeI = nodeI->next)
			{
				if (nodeI->value > nodeI->next->value)
				{
					swapped = true;

					auto nextNode = nodeI->next;

					if (nodeI == head)
					{
						head = nextNode;
					}

					if (previousNode != nullptr)
					{
						previousNode->next = nextNode;
					}

					auto nextNextNode = nextNode->next;
					nextNode->next = nodeI;
					nodeI->next = nextNextNode;

					nodeI = nextNode;

					previousNode = nodeI;

					swapped = true;
				}
			}
		}
	}
};

int main(int argc, char* argv[])
{
	auto newList = (List<int>*) malloc(sizeof(List<int>));

	Node<int>* previousNode;
	Node<int>* newNode = (Node<int>*) malloc(sizeof(Node<int>));
	newNode->value = 5;
	newNode->next = nullptr;
	previousNode = newNode;

	newList->head = newNode;

	newNode = (Node<int>*) malloc(sizeof(Node<int>));
	newNode->value = 4;
	newNode->next = nullptr;
	previousNode->next = newNode;
	previousNode = newNode;

	newNode = (Node<int>*) malloc(sizeof(Node<int>));
	newNode->value = 3;
	newNode->next = nullptr;
	previousNode->next = newNode;
	previousNode = newNode;

	newList->bubbleSort();

	return 0;
}

