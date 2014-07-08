#ifndef MYQUEUE_H
#define MYQUEUE_H

namespace Queue
{
	class LinkedListNode;

	class MyQueue
	{
	private:
		LinkedListNode* head;
		LinkedListNode* tail;

	public:
		MyQueue();
		void add(int data);
		int remove();
	};
}

#endif