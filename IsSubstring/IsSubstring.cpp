#include <iostream>

bool isSubstring(std::string s1, std::string s2)
{
	for (auto startPosS1 = 0; startPosS1 < s1.length(); ++startPosS1)
	{
		int i = startPosS1;
		bool areEqual = true;
		int j = 0;
		while (j < s2.length() && i < s1.length())
		{
			if (s1[i++] != s2[j++])
			{
				areEqual = false;
				break;
			}
		}

		if (areEqual == true && j == s2.length())
		{
			return true;
		}
	}

	return false;
}

bool isSubstringFast(std::string s1, std::string s2)
{
	const int factor = 2;
	long long hashS1 = 0, hashS2 = 0;

	long long pow = 1;
	for (int i = 0; i < s2.length() - 1; ++i)
	{
		pow *= factor;
	}

	for (int i = 0; i < s2.length(); ++i)
	{
		hashS2 = hashS2*factor + s2[i];
	}

	for (int i = 0; i < s1.length(); ++i)
	{
		if (i >= s2.length())
		{
			int pos = i - s2.length();
			hashS1 -= (s1[pos])*pow;
		}

		hashS1 = hashS1*factor + s1[i];

		if (hashS1 == hashS2 && i >= s2.length() -1)
		{
			return true;
		}
	}

	return false;
}

int main(int argc, char* argv[])
{
	std::string s1 = "abcdef", s2 = "hg";
	std::cout << isSubstringFast(s1, s2) << std::endl;
}