#include <iostream>
#include <limits>

typedef struct BinaryVector
{
	char* elements;

	int length;

	static BinaryVector* newBinaryVector(int length)
	{
		auto bv = (BinaryVector*)malloc(sizeof(BinaryVector));

		bv->length = (length / CHAR_BIT + 1);

		bv->elements = (char*)malloc(bv->length*sizeof(char));

		memset(bv->elements, 0, bv->length);

		return bv;
	}

	bool isSet(int pos)
	{
		int posElement = pos / CHAR_BIT;

		char n = 1 << pos % CHAR_BIT;

		char bit = elements[posElement] & n;

		char result = bit >> (pos % CHAR_BIT);

		return result == 1;
	}

	void set(int pos)
	{
		int posElement = pos / CHAR_BIT;

		char just1BitSet = 1 << (pos % CHAR_BIT);

		elements[posElement] |= just1BitSet;
	}

	void unSet(int pos)
	{
		int posElement = pos / CHAR_BIT;

		char allBitsSet = char((1 << (CHAR_BIT + 1)) - 1);

		char allBitsSetUnlessBitPos = allBitsSet - (1 << (pos % CHAR_BIT));

		elements[posElement] &= allBitsSetUnlessBitPos;
	}
}BinaryVector;

int main(int argc, char* argv[])
{
	auto bv = BinaryVector::newBinaryVector(9);

	bv->set(2);
	bv->set(7);
	std::cout << "Bit 2 value is " << bv->isSet(2) << std::endl;
	std::cout << "Bit 7 value is " << bv->isSet(7) << std::endl;

	bv->unSet(2);
	std::cout << "Bit 2 value is " << bv->isSet(2) << std::endl;
	std::cout << "Bit 7 value is " << bv->isSet(7) << std::endl;
}