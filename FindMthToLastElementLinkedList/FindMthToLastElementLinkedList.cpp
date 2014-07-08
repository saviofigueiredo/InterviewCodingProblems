#include <exception>
#include <iostream>

template <typename T>
struct Node
{
	Node* next;
	T data;

	Node(int newData)
	{
		data = newData;
		next = nullptr;
	}

	void append(int data)
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

	int findMthToLastElement(int m)
	{
		int count = 0;

		Node* current = this;
		Node* mthElement = this;

		while (current != nullptr)
		{
			++count;

			if (count > m)
			{
				mthElement = mthElement->next;
			}

			current = current->next;
		}

		if (count < m)
		{
			throw std::exception("findMthToLastElement called with invalid parameter");
		}

		return mthElement->data;
	}
};

int main(int argc, char* argv[])
{
	auto node1 = new Node<int>(1);
	node1->append(2);
	node1->append(3);
	node1->append(4);
	node1->append(5);
	node1->append(6);
	node1->append(7);

	std::cout << node1->findMthToLastElement(3) << std::endl;
	std::cout << node1->findMthToLastElement(5) << std::endl; 
	std::cout << node1->findMthToLastElement(6) << std::endl;
}