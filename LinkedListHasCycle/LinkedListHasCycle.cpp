#include <iostream>

template <typename T>
struct Node
{
	Node* next;
	T data;

	Node(T newData)
	{
		data = newData;
		next = nullptr;
	}

	void append(T data)
	{
		if (next == nullptr)
		{
			auto newNode = new Node(data);
			next = newNode;
		}
		else
		{
			next->append(data);
		}
	}
};

template <typename T>
struct LinkedList
{
	Node<T>** head;

	bool hasCycle()
	{
		auto current = *head;

		Node<T>* fast;

		if (current == nullptr)
		{
			return false;
		}

		fast = current->next;

		while (fast != nullptr)
		{
			fast = fast->next;

			if (fast == current)
			{
				return true;
			}

			if (fast != nullptr)
			{
				fast = fast->next;
			}

			if (fast == current)
			{
				return true;
			}

			current = current->next;
		}

		return false;
	}

	LinkedList()
	{
		head = (Node<T>**)malloc(sizeof(Node<T>*));
		*head = nullptr;
	}
};

int main(int argc, char* argv[])
{
	auto list = new LinkedList<int>();

	auto node1 = new Node<int>(1);
	node1->append(2);
	node1->append(3);
	node1->append(4);
	node1->append(5);
	node1->append(6);
	node1->append(7);
	node1->append(8);
	node1->append(9);
	node1->append(10);
	node1->append(11);

	*list->head = node1;

	std::cout << list->hasCycle() << std::endl;
}