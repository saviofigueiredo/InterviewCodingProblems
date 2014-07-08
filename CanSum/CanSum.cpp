#include "stdafx.h"
#include <iostream>

bool canSum(int v[], int length, int sum, int pos = 0)
{
	if (pos >= length)
	{
		return false;
	}

	if (v[pos] == sum)
	{
		return true;
	}

	if (pos == length - 1)
	{
		return false;
	}

	return canSum(v, length, sum, pos + 1) || canSum(v, length, sum - v[pos], pos + 1);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int v[] = { 3, 7, 1, 8, -3 };
	
	std::cout << canSum(v, sizeof(v)/sizeof(int), 2) ;

	return 0;
}

