#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

namespace Queue
{
	class LinkedListNode
	{
	private:
		LinkedListNode* next;
		int data;
	public:
		LinkedListNode();
		int getData();
		void setNext(LinkedListNode* newNextNode);

		void setData(int newData);
		LinkedListNode* getNext();
	};
}

#endif