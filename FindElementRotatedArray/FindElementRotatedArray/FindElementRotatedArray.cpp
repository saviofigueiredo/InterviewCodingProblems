// FindElementRotatedArray.cpp : Defines the entry point for the console application.
//

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). 
How do you find an element in the rotated array efficiently?
*/

#include "stdafx.h"
#include <iostream>

int findElementRotatedArray(int _array[], int _length, int _searched)
{
	int start = 0;
	int end = _length - 1;
	int mid = start + (end - start)/2;

	while(start <= end)
	{
		if (_array[mid] == _searched)
		{
			return mid;
		}

		else if (_array[end] >= _array[mid]) // right side is sorted
		{
			if (_searched >= _array[mid] && _searched <= _array[end])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		else 
		{
			if (_searched <= _array[mid] && _searched >= _array[start])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		mid = start + (end - start)/2;
	}

	return -1;
}
 
int _tmain(int argc, _TCHAR* argv[])
{
	int array[] = {4, 5, 6, 7, 0, 1, 2};

	for (int i = 0; i < sizeof(array)/sizeof(int); ++i)
	{
		std::cout << "Searching for " << array[i] << " that should be found at " << i << std::endl;

		std::cout << "Function returned  " << findElementRotatedArray(array, sizeof(array)/sizeof(int), array[i]) << std::endl;
	}

	return 0;
}

