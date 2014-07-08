#include <iostream>
#include <ctime>
#include <unordered_map>

/*
"Find the first character in a stream which is not repeated in the rest of the stream. 
Please note that you are being provided a stream as a source for these characters. 
The stream is guaranteed to eventually terminate (i.e. return false from a call to the hasNext() method), 
though it could be very long. You will access this stream through the provided interface methods. 
A call to hasNext() will return whether the stream contains any more characters to process. A call to getNext() 
will return the next character to be processed in the stream. It is not possible to restart the stream. 
Example: Input: aAbBABac Output: b In this example, the character ‘b’ is the 
first character in the stream which is not repeated in the stream.
*/

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
};

template <typename T>
struct Queue
{
	Node<T>* head;
	Node<T>* tail;

	void add(T data)
	{
		auto nodeToAdd = new Node<T>(data);

		if (head == nullptr)
		{
			head = nodeToAdd;
			tail = nodeToAdd;
		}
		else
		{
			tail->next = nodeToAdd;
			tail = nodeToAdd;
		}
	}

	void remove(T data)
	{
		if (head == nullptr)
		{
			return;
		}

		if (head->data == data)
		{
			remove();
			return;
		}

		Node<T>* previous = nullptr;
		auto current = head;

		while (current != nullptr)
		{
			if (current->data == data)
			{
				previous->next = current->next;
				return;
			}
			previous = current;
			current = current->next;
		}
	}

	Node<T>* remove()
	{
		if (head == nullptr)
		{
			return nullptr;
		}

		auto nodeToReturn = head;

		head = head->next;

		if (head == nullptr)
		{
			tail = nullptr;
		}

		return nodeToReturn;
	}

	Queue()
	{
		head = nullptr;
		tail = nullptr;
	}
};

typedef struct MyStream
{
	char* elements;
	int count;
	int current;

	bool hasNext()
	{
		if (current < count)
		{
			return true;
		}
		return false;
	}

	char getNext()
	{
		return elements[current++];
	}

	MyStream(int n)
	{
		count = n;
		current = 0;
		elements = (char*)malloc(count*sizeof(char));
		srand(unsigned int(time(nullptr)));
		for (int i = 0; i < count; ++i)
		{
			elements[i] = (rand() % 26) + 65;
		}
	}

	void print()
	{
		std::cout << "Stream" << std::endl;

		reset();
		while (hasNext())
		{
			std::cout << getNext() << " ";
		}

		std::cout << std::endl;

		reset();
	}

	void reset()
	{
		current = 0;
	}

	char getFirstCharJustAppearOnce()
	{
		std::unordered_map<char, bool> charsPresentedJustOnce;
		auto queue = new Queue<char>();

		while (hasNext())
		{
			auto currentChar = getNext();

			if (charsPresentedJustOnce.find(currentChar) == charsPresentedJustOnce.end())
			{
				queue->add(currentChar);

				charsPresentedJustOnce.insert(std::make_pair(currentChar, true));
			}
			else
			{
				queue->remove(currentChar);

				charsPresentedJustOnce[currentChar] = false;
			}
		}

		return queue->remove()->data;
	}
}MyStream;

int main()
{
	auto stream = new MyStream(20);

	stream->print();

	std::cout << "First character is " << stream->getFirstCharJustAppearOnce();
}
	