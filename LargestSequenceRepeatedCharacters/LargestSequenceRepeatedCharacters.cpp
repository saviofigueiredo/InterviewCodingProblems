#include <string>
#include <iostream>

int largestSequenceRepeatedCharacters(std::string s)
{
	int largestSequenceSize = 0;
	int i = 0;

	while (i < s.length())
	{
		int posStart = i;
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