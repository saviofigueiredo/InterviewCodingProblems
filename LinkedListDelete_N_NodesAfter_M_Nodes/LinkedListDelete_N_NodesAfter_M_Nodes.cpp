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

	void append(Node<T>* node)
	{
		if (next == nullptr)
		{
			next = node;
		}
		else
		{
			next->append(node);
		}
	}

	void print()
	{
		std::cout << data << " ";
		if (next != nullptr)
		{
			next->print();
		}
	}

	void deleteNodes(int quantityToDelete, int quantityToByPass)
	{
		auto byPassing = true;
		auto count = quantityToByPass;

		Node<T>* previous = nullptr;
		auto current = this;

		if (quantityToByPass == 0)
		{
			current = nullptr;
			return;
		}

		while (current)
		{
			--count;

			if (byPassing)
			{
				previous = current;
			}
			else
			{
				previous->next = current->next;
			}

			current = current->next;

			if (count == 0)
			{
				byPassing = !byPassing;

				if (byPassing)
				{
					count = quantityToByPass;
				}
				else
				{
					count = quantityToDelete;
				}
			}
		}
	}
};

int main(int argc, char* argv)
{
	auto l1 = new Node<int>(1);
	l1->append( new Node<int>(2));
	l1->append( new Node<int>(3));
	l1->append( new Node<int>(4));
	l1->append( new Node<int>(5));
	l1->append( new Node<int>(6));
	l1->append( new Node<int>(7));
	l1->append( new Node<int>(8));
	l1->append( new Node<int>(9));
	l1->append( new Node<int>(10));
	l1->append( new Node<int>(11));
	l1->append( new Node<int>(12));
	l1->append( new Node<int>(13));
	l1->append( new Node<int>(14));

	l1->deleteNodes(1, 3);

	l1->print();
}