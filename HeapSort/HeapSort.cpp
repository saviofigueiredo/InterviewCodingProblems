#include <iostream>

#define PriorityQueueSize 100

typedef struct 
{
	int q[PriorityQueueSize + 1];

	int length;
} PriorityQueue;

void priorityQueueInit(PriorityQueue* priorityQueue)
{
	priorityQueue->length = 0;
}

int priorityQueueParent(int n)
{
	if (n == 1)
	{
		return -1;
	}

	return n/ 2;
}

int priorityQueueYoungChild(int n)
{
	return 2 * n;
}

void priorityQueueSwap(PriorityQueue* priorityQueue, int pos1, int pos2)
{
	int old = priorityQueue->q[pos1];
	priorityQueue->q[pos1] = priorityQueue->q[pos2];
	priorityQueue->q[pos2] = old;
}

void priorityQueueBubbleUp(PriorityQueue* priorityQueue, int pos)
{
	if (priorityQueueParent(pos) == -1)
	{
		return;
	}

	if (priorityQueue->q[priorityQueueParent(pos)] > priorityQueue->q[pos])
	{
		priorityQueueSwap(priorityQueue, pos, priorityQueueParent(pos));
		priorityQueueBubbleUp(priorityQueue, priorityQueueParent(pos));
	}
}
 
void priorityQueueBubbleDown(PriorityQueue* priorityQueue, int pos)
{
	int minIndex = pos;

	int youngChild = priorityQueueYoungChild(pos);
	int secondChild = youngChild + 1;
	if (youngChild <= priorityQueue->length && priorityQueue->q[youngChild] < priorityQueue->q[minIndex])
	{
		minIndex = youngChild;
	}
	if (secondChild <= priorityQueue->length && priorityQueue->q[secondChild] < priorityQueue->q[minIndex])
	{
		minIndex = secondChild;
	}

	if (minIndex != pos)
	{
		priorityQueueSwap(priorityQueue, pos, minIndex);
		priorityQueueBubbleDown(priorityQueue, minIndex);
	}
}

void priorityQueueInsert(PriorityQueue* priorityQueue, int x)
{
	if (priorityQueue->length >= PriorityQueueSize)
	{
		std::cout << "priority queue overflow while inserting " << x << std::endl;
	}
	else
	{
		priorityQueue->length++;
		priorityQueue->q[priorityQueue->length] = x;
		priorityQueueBubbleUp(priorityQueue, priorityQueue->length);
	}
}

void priorityQueueMakeHeap(PriorityQueue* priorityQueue, int v[], int n)
{
	int i;
	priorityQueueInit(priorityQueue);

	for (i = 0; i < n; ++i)
	{
		priorityQueueInsert(priorityQueue, v[i]);
	}
}

int priorityQueueExtractMin(PriorityQueue* priorityQueue)
{
	int min = -1;

	if (priorityQueue->length == 0)
	{
		std::cout << "The heap is empty" << std::endl;
	}
	else
	{
		min = priorityQueue->q[1];
		priorityQueue->q[1] = priorityQueue->q[priorityQueue->length];
		priorityQueue->length--;

		priorityQueueBubbleDown(priorityQueue, 1);
	}

	return min;
}

void heapSort(int v[], int length)
{
	PriorityQueue priorityQueue;

	priorityQueueMakeHeap(&priorityQueue, v, length);

	for (int i = 0; i < length; ++i)
	{
		v[i] = priorityQueueExtractMin(&priorityQueue);
	}
}

int main(int argc, char* argv[])
{
	int v[] = { 6, 3, 2, 98, 23, 15, 1};

	heapSort(v, sizeof (v)/sizeof(int));

	return 0;
}