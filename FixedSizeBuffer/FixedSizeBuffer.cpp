#include <iostream>

template <typename T>
struct FixedSizeBuffer
{
	T* data;
	int storedQty;
	int length;
	int head;
	int tail;

	FixedSizeBuffer(int bufferLength)
	{
		data = (T*)malloc(bufferLength*sizeof(T));
		length = bufferLength;
		head = 0;
		tail = 0;
		storedQty = 0;
	}

	char* remove(int lengthToRemove)
	{
		if (lengthToRemove > storedQty)
		{
			throw std::exception("The buffer does not have this quantity of elements to be removed");
		}

		auto bytes = (T*)malloc(lengthToRemove*sizeof(T));

		auto i = head;
		auto j = 0;

		while (j < lengthToRemove)
		{
			bytes[j++] = data[i++];
			i %= length;
		}

		storedQty -= length;
		head = i;

		return bytes;
	}
	
	void add(T* dataToBeAdded, int lengthDataToBeAdded)
	{
		if (length - storedQty < lengthDataToBeAdded)
		{
			throw std::exception("The buffer does not have capacity to store this quantity");
		}

		auto i = tail;
		auto j = 0;

		while (j < lengthDataToBeAdded)
		{
			data[i++] = dataToBeAdded[j++];
			i %= length;
		}

		storedQty += lengthDataToBeAdded;
		tail = i;
	}
};

int main(int argc, char* argv[])
{
	auto buffer = new FixedSizeBuffer<char>(10);

	buffer->add("abcdefghij", 10);

	buffer->remove(3);

	return EXIT_SUCCESS;
}