/*
	Given a string, find the biggest substring that does not have any repeated char.
*/
#include <iostream>

int biggestSubstring(std::string s)
{
	int v[256];

	int start = 0, biggest = 0, currentSize = 0;

	for (int i = 0; i < 256; ++i)
	{
		v[i] = 0;
	}

	for (int i = 0; i < s.length(); ++i)
	{
		if (v[s[i]] == 1)
		{
			while (s[start] != s[i])
			{
				v[s[start]] = 0;
				++start;

				--currentSize;
			}
			
			v[s[start]] = 0;
			++start;
		}
		else
		{
			++currentSize;

			if (currentSize > biggest)
			{
				biggest = currentSize;
			}
		}

		v[s[i]] = 1;
	}

	return biggest;
}

int main(int argc, char* argv[])
{
	std::string s = "abcbaaafghijlm";
	std::cout << biggestSubstring(s) << std::endl;
}