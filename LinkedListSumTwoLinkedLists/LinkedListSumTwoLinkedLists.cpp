#include <iostream>
#include <stack>

/*
	Given two linked lists where each linked list node holds a single digit positive integer value,
	create a method that receives the two linked lists as parameters and returns a third linked list
	that should be the sum of those linked lists.
	For example:

	1->3->5->nullptr
	2->3->2->nullptr

	Return value
	3->6->7->nullptr
*/

template <typename T>
struct Node
{
	T data;
	Node* next;

	Node(T newData)
	{
		data = newData;
		next = nullptr;
	}

	void append(int data)
	{
		if (next == nullptr)
		{
			next = new Node(data);
		}
		else
		{
			next->append(data);
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

	void getStackOfNodes(std::stack<T>& stackOfNodes)
	{
		stackOfNodes.push(data);

		if (next)
		{
			next->getStackOfNodes(stackOfNodes);
		}
	}
};

template <typename T>
T popFromStackOrDefault(std::stack<T>& stack, T defaultValue)
{
	if (stack.empty() == true)
	{
		return defaultValue;
	}

	auto valueFromTop = stack.top();
	stack.pop();
	return valueFromTop;
}

template <typename T>
Node<T>* getLinkedListFromStack(std::stack<T> stack)
{
	Node<T>* head = nullptr;
	Node<T>* previous = nullptr;

	while (stack.empty() == false)
	{
		auto newNode = new Node<T>(stack.top());
		stack.pop();

		if (previous == nullptr)
		{
			head = newNode;
			previous = head;
		}
		else
		{
			previous->next = newNode;
			previous = newNode;
		}
	}

	return head;
}

Node<int>* sum(Node<int>* n1, Node<int>* n2)
{
	std::stack<int> stack1;
	std::stack<int> stack2;
	std::stack<int> resultStack;

	if (n1 != nullptr)
	{
		n1->getStackOfNodes(stack1);
	}
	if (n2 != nullptr)
	{
		n2->getStackOfNodes(stack2);
	}

	int overflow = 0;

	while (stack1.empty() == false || stack2.empty() == false)
	{
		auto numberFromN1 = popFromStackOrDefault<int>(stack1, 0);
		auto numberFromN2 = popFromStackOrDefault<int>(stack2, 0);

		if (numberFromN1 > 9 || numberFromN1 < 0)
		{
			throw std::exception("Invalid number found at the first linked list: " + numberFromN1);
		}
		if (numberFromN2 > 9 || numberFromN2 < 0)
		{
			throw std::exception("Invalid number found at the second linked list: " + numberFromN2);
		}

		auto sum = numberFromN1 + numberFromN2 + overflow;

		if (sum > 9)
		{
			overflow = 1;
			sum -= 10;
		}
		else
		{
			overflow = 0;
		}

		resultStack.push(sum);
	}

	if (overflow != 0)
	{
		resultStack.push(overflow);
	}

	return getLinkedListFromStack(resultStack);
}

int main(int argc, char* argv[])
{
	auto l1 = new Node<int>(4);
	l1->append(3);
	l1->append(7);

	auto l2 = new Node<int>(7);
	l2->append(8);
	l2->append(2);
	l2->append(6);
	l2->append(5);

	auto l3 = sum(l1, l2);

	l3->print();
}