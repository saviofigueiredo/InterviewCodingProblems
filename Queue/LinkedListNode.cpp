#include "LinkedListNode.h"

namespace Queue
{
	LinkedListNode::LinkedListNode()
	{
		next = nullptr;
	}

	int LinkedListNode::getData()
	{
		return data;
	}

	void LinkedListNode::setNext(LinkedListNode* newNextNode)
	{
		next = newNextNode;
	}

	void LinkedListNode::setData(int newData)
	{
		data = newData;
	}

	LinkedListNode* LinkedListNode::getNext()
	{
		return next;
	}
}