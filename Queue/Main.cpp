#include <iostream>
#include "MyQueue.h"

int main(int argc, char* argv[])
{
	Queue::MyQueue queue;

	queue.add(1);
	queue.add(2);

	std::cout << queue.remove() << std::endl;
	std::cout << queue.remove() << std::endl;

	return EXIT_SUCCESS;
}