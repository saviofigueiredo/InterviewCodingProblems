/*
From http://rosettacode.org/wiki/Look-and-say_sequence

The Look and say sequence is a recursively defined sequence of numbers studied most notably by John Conway.

Sequence Definition
Take a decimal number
Look at the number, visually grouping consecutive runs of the same digit.
Say the number, from left to right, group by group; as how many of that digit there are - followed by the digit grouped.
This becomes the next number of the sequence.
An example:
Starting with the number 1, you have one 1 which produces 11.
Starting with 11, you have two 1's i.e. 21
Starting with 21, you have one 2, then one 1 i.e. (12)(11) which becomes 1211
Starting with 1211 you have one 1, one 2, then two 1's i.e. (11)(12)(21) which becomes 111221

Task description
Write a program to generate successive members of the look-and-say sequence.

1
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211
11131221133112132113212221
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <exception>
#include <unordered_map>

std::string lookAndSay(int n, std::string previous, std::unordered_map<int, int>& nextNumbersMap)
{
	if (n == 0)
	{
		return previous;
	}
	if (n < 0)
	{
		throw std::exception("");
	}

	std::string nextSequence;

	for (auto i = 0; i < previous.size(); ++i)
	{
		auto digit = previous[i] - '0';
		auto entry = digit;

		for (auto index = 10; i + 1 < previous.size() && previous[i + 1] == previous[i]; ++i, index *= 10)
		{
			entry += digit*index;
		}

		nextSequence.append(std::to_string(nextNumbersMap[entry]));
	}

	--n;
	std::cout << nextSequence << std::endl;
	return lookAndSay(n, nextSequence, nextNumbersMap);
}

std::string lookAndSay(int n)
{
	std::unordered_map<int, int> nextNumbersMap;

	nextNumbersMap.insert(std::make_pair(1, 11));
	nextNumbersMap.insert(std::make_pair(2, 12));
	nextNumbersMap.insert(std::make_pair(3, 13));
	nextNumbersMap.insert(std::make_pair(11, 21));
	nextNumbersMap.insert(std::make_pair(22, 22));
	nextNumbersMap.insert(std::make_pair(33, 23));
	nextNumbersMap.insert(std::make_pair(111, 31));
	nextNumbersMap.insert(std::make_pair(222, 32));
	nextNumbersMap.insert(std::make_pair(333, 33));

	if (n > 0)
	{
		std::cout << "1" << std::endl;
	}

	return lookAndSay(n, "1", nextNumbersMap);
}

int main(int argc, char* argv[])
{
	lookAndSay(10);

	return EXIT_SUCCESS;
}

