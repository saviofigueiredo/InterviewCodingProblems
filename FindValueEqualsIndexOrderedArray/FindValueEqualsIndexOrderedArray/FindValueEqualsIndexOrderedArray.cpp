// FindValueEqualsIndexOrderedArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int findValue(int _array [], int _length)
{
	int start = 0;
	int end = _length - 1;

	int mid = (end + start)/2;

	while (end >= start)
	{
		if (mid == _array[mid])
		{
			return mid;
		}

		if (mid < _array[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}

		mid = (end + start) / 2;
	}

	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int array1[] = {1, 2, 4, 5, 6, 7};
	int array2[] = {0, 3, 4, 5, 6, 7};
	int array3[] = {-1, 0, 1, 2, 4, 7};
	int array4[] = {-1, 0, 1, 2, 3, 5};
	int array5[] = {-1, 0, 1, 3, 5, 6};
    
	std::cout << findValue(array1, sizeof(array1)/sizeof(int)) << std::endl;
    std::cout << findValue(array2, sizeof(array2)/sizeof(int)) << std::endl;
	std::cout << findValue(array3, sizeof(array3)/sizeof(int)) << std::endl;
    std::cout << findValue(array4, sizeof(array4)/sizeof(int)) << std::endl;
	std::cout << findValue(array5, sizeof(array5)/sizeof(int)) << std::endl;
}

