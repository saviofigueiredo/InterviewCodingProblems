// ListIntersection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map> 
#include <list>
#include <iostream>
#include <utility>

int _tmain(int argc, _TCHAR* argv[])
{
	int array1[] = { 1, 3, 5, 5, 4, 6, 7, 8, 9 };
	int array2[] = { 2, 3, 5, 10, 5 };
	std::list<int> intersection;

	std::unordered_map<int, bool> occurrences;
	std::unordered_map<int, bool> elementsAlreadyAdded;

	for (int i = 0; i < sizeof(array1) / sizeof(int); ++i)
	{
		occurrences.insert(std::make_pair(array1[i], true));
	}

	for (int i = 0; i < sizeof(array2) / sizeof(int); ++i)
	{
		if (occurrences.find(array2[i]) != occurrences.end() && elementsAlreadyAdded.find(array2[i]) == elementsAlreadyAdded.end())
		{
			intersection.push_back(array2[i]);
			elementsAlreadyAdded.insert(std::make_pair(array2[i], true));
		}
	}

	for (std::list<int>::iterator it = intersection.begin(); it != intersection.end(); ++it)
	{
		std::cout << (*it) << " ";
	}

	return 0;
}

