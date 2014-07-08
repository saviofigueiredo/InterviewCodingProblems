// FindPivotRotatedArray.cpp : Defines the entry point for the console application.
//

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). 
How do you find an element in the rotated array efficiently? 
You may assume no duplicate exists in the array.
*/

#include "stdafx.h"

#include <iostream>

int findPivotRotatedArray(int _array[], int _length)
{
	int start = 0;
	int end = _length - 1;
	int mid = (start + end)/2;

	std::cout << std::endl << "NEW SEARCH FOR ARRAY" << std::endl;
	for (int i = 0; i < _length; ++i)
	{
		std::cout << _array[i] << " ";
	}

	std::cout << std::endl;

	while(start <= end)
	{
		if (_array[end] >= _array[mid] && (mid == 0 || _array[mid - 1] > _array[mid] ))
		{
			std::cout << "Element found at index " << mid << std::endl;

			return mid;
		}
		else if (_array[end] > _array[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}

		mid = (start + end) / 2;
	}

	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{

	int array1[] = { 1 };
	int array2[] = { 1, 2 };
	int array3[] = { 2, 1 };
	int array4[] = { 1, 2, 3 };
	int array5[] = { 3, 1, 2 };
	int array6[] = { 2, 3, 1 };
	int array7[] = { 1, 2, 3, 4, 5 };
	int array8[] = { 2, 3, 4, 5, 1 };
	int array9[] = { 3, 4, 5, 1, 2 };
	int array10[] = { 4, 5, 1, 2, 3 };
	int array11[] = { 5, 1, 2, 3, 4 };
	int array12[] = { 1, 2, 3, 4, 5, 6 };
	int array13[] = { 2, 3, 4, 5, 6, 1 };
	int array14[] = { 3, 4, 5, 6, 1, 2 };
	int array15[] = { 4, 5, 6, 1, 2, 3 };
	int array16[] = { 5, 6, 1, 2, 3, 4 };
	int array17[] = { 6, 1, 2, 3, 4, 5 };
	int array18[] = { 6, 8, 1, 2, 4, 5 };

	findPivotRotatedArray(array1, sizeof(array1)/sizeof(int));   // 0
	findPivotRotatedArray(array2, sizeof(array2)/sizeof(int));   // 0
	findPivotRotatedArray(array3, sizeof(array3)/sizeof(int));   // 1
	findPivotRotatedArray(array4, sizeof(array4)/sizeof(int));   // 0
	findPivotRotatedArray(array5, sizeof(array5)/sizeof(int));   // 1
	findPivotRotatedArray(array6, sizeof(array6)/sizeof(int));   // 2
	findPivotRotatedArray(array7, sizeof(array7)/sizeof(int));   // 0
	findPivotRotatedArray(array8, sizeof(array8)/sizeof(int));   // 4
	findPivotRotatedArray(array9, sizeof(array9)/sizeof(int));   // 3
	findPivotRotatedArray(array10, sizeof(array10)/sizeof(int)); // 2 
	findPivotRotatedArray(array11, sizeof(array11)/sizeof(int)); // 1
	findPivotRotatedArray(array12, sizeof(array12)/sizeof(int)); // 0
	findPivotRotatedArray(array13, sizeof(array13)/sizeof(int)); // 5
	findPivotRotatedArray(array14, sizeof(array14)/sizeof(int)); // 4
	findPivotRotatedArray(array15, sizeof(array15)/sizeof(int)); // 3
	findPivotRotatedArray(array16, sizeof(array16)/sizeof(int)); // 2
	findPivotRotatedArray(array17, sizeof(array17)/sizeof(int)); // 1
	findPivotRotatedArray(array18, sizeof(array18)/sizeof(int)); // 2

	return 0;
}

