#include <iostream>

typedef struct FixedSizeBuffer
{
	char* data;
	int storedQty;
	int length;
	int head;
	int tail;
};

void initialize(FixedSizeBuffer* buffer, int length)
{
	buffer->data = (char*)malloc(length*sizeof(char));
	buffer->length = length;
	buffer->head = 0;
	buffer->tail = 0;
	buffer->storedQty = 0;
}

char* remove(FixedSizeBuffer* buffer, int length)
{
	if (length > buffer->storedQty)
	{
		throw std::exception("The buffer does not have this quantity of elements to be removed");
	}

	char* bytes = (char*)malloc(length*sizeof(char));

	auto i = buffer->head;
	auto j = 0;

	while (j < length)
	{
		bytes[j++] = buffer->data[i++];
		i %= buffer->length;
	}

	buffer->storedQty -= length;
	buffer->head = i;
}

void add(FixedSizeBuffer* buffer, char* dataToBeAdded, int lengthDataToBeAdded)
{
	if (buffer->length - buffer->storedQty < lengthDataToBeAdded)
	{
		throw std::exception("The buffer does not have capacity to store this quantity");
	}

	auto i = buffer->tail;
	auto j = 0;

	while (j < lengthDataToBeAdded)
	{
		buffer->data[i++] = dataToBeAdded[j++];
		i %= buffer->length;
	}

	buffer->storedQty += lengthDataToBeAdded;
	buffer->tail = i;
}

int main(int argc, char* argv[])
{
	FixedSizeBuffer* buffer = (FixedSizeBuffer*) malloc(sizeof(FixedSizeBuffer));

	initialize(buffer, 10);

	add(buffer, "abcdefghij", 10);

	remove(buffer, 3);

	return EXIT_SUCCESS;
}