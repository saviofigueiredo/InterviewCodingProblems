// FindGapOrderedSequentialArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int findGap(int v[], int length)
{
	int start = 0;
	int end = length - 1;

	if (length == 0)
	{
		return -1;
	}

	if (v[0] != 1)
	{
		return 1;
	}

	while (end >= start)
	{
		int mid = start + (end - start)/2;

		if (v[mid] - v[mid - 1] != 1)
		{
			return mid;
		}

		if (v[mid] == mid + 1)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int v[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
	std::cout << findGap(v, sizeof(v)/sizeof(int)) << std::endl;

	int v2[] = {1, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << findGap(v2, sizeof(v2)/sizeof(int)) << std::endl;

	return 0;
}

