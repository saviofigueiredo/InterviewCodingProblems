#include "MyQueue.h"
#include "LinkedListNode.h"
#include <exception>

namespace Queue
{
	MyQueue::MyQueue()
	{
		head = nullptr;
		tail = nullptr;
	}

	void MyQueue::add(int data)
	{
		auto newElement = new LinkedListNode();
		newElement->setData(data);

		if (head == nullptr)
		{
			head = newElement;
		}
		else
		{
			tail->setNext(newElement);
		}

		tail = newElement;
	}

	int MyQueue::remove()
	{
		if (head == nullptr)
		{
			throw std::exception("Remove cannot be called with an empty queue");
		}

		auto previousHead = head;
		auto dataToBeReturned = head->getData();

		head = previousHead->getNext();

		delete previousHead;

		if (head == nullptr)
		{
			tail = nullptr;
		}

		return dataToBeReturned;
	}
}