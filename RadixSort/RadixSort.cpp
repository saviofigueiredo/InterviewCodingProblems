// RadixSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

void radixSortWithVector(int v[])
{
	std::vector<int> buckets[10];
	int biggestValue = v[0];

	for (int i = 1; i < sizeof(v) / sizeof(int); ++i)
	{
		if (v[i] > biggestValue)
		{
			biggestValue = v[i];
		}
	}

	int r = 10;

	while (r < biggestValue * 10)
	{
		int d = r / 10;

		for (int i = 0; i < sizeof(v) / sizeof(int); ++i)
		{
			int index = (v[i] % r) / d;

			buckets[index].push_back(v[i]);
		}

		// Put the values back into the array.
		int count = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (std::vector<int>::iterator it = buckets[i].begin(); it != buckets[i].end(); ++it)
			{
				v[count] = (*it);
				++count;
			}

			buckets[i].clear();
		}

		r *= 10;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

