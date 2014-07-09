#include <iostream>
#include <string>

bool StringContainsPermutationSubstring(std::string s1, std::string s2)
{
	int v[256];

	for (size_t i = 0; i < 256; ++i)
	{
		v[i] = 0;
	}

	for (size_t i = 0; i < s2.length(); ++i)
	{
		v[s2[i]]++;
	}

	for (size_t i = 0; i < s1.length(); ++i)
	{
		for (size_t j = i; j < s2.length() && j < s1.length(); ++j)
		{
			v[s1[j]]--;
		}

		bool isPermutation = true;

		for (int j = 0; j < 256; ++j)
		{
			if (v[j] != 0)
			{
				isPermutation = false;
			}
		}

		if (isPermutation == true)
		{
			return true;
		}

		for (size_t j = i; j < s2.length() && j < s1.length(); ++j)
		{
			v[s1[j]]++;
		}
	}

	return false;
}

int main(int argc, char* argv[])
{
	std::string s1 = "abcdefgh";
	std::string s2 = "aba";

	if (StringContainsPermutationSubstring(s1, s2))
	{
		std::cout << s1 << " contains any permutation of " + s2 << std::endl;
	}
	else
	{
		std::cout << s1 << " does not contain any permutation of " + s2 << std::endl;
	}
}