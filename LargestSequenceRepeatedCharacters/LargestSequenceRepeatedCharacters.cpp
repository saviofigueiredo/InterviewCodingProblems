#include <string>
#include <iostream>

int largestSequenceRepeatedCharacters(std::string s)
{
	size_t largestSequenceSize = 0;
	size_t i = 0;

	while (i < s.length())
	{
		size_t posStart = i;
		++i;

		while (i < s.length() && s[i] == s[posStart])
		{
			++i;
		}

		if (i - posStart > largestSequenceSize)
		{
			largestSequenceSize = i - posStart;
		}
	}

	return largestSequenceSize;
}

int main(int argc, char* argv[])
{
	std::cout << largestSequenceRepeatedCharacters("aabbbbcccdddddddddeeeffffffffffg");
}