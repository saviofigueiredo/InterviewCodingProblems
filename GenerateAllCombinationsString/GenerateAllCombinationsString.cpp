// GenerateAllCombinationsString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>

std::vector<std::string> generateAllCombinations(std::string s)
{
	std::vector<std::string> v;
	std::vector<std::string> combinations;

	if (s.size() == 0)
	{
		return v;
	}

	if (s.size() == 1)
	{
		v.push_back(s);

		return v;
	}

	char characterToMix = s.at(0);
	s = s.substr(1, s.size() - 1);

	combinations = generateAllCombinations(s);

	for (size_t i = 0; i < combinations.size(); ++i)
	{
		std::string combination = combinations[i];

		for (size_t j = 0; j <= combination.size(); ++j)
		{
			std::string left = combination.substr(0, j);
			std::string right = combination.substr(j, combination.size() - j);
			v.push_back(left + characterToMix + right);
		}
	}

	return v;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::string> combinations = generateAllCombinations("ab");

	combinations = generateAllCombinations("abc");

	combinations = generateAllCombinations("abcd");

	combinations = generateAllCombinations("savio");

	return 0;
}

