// ReplaceSpacesByPercent20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	char statement[100] = " Should replace  spaces by percentage20 ";
	int numberOfSpaces = 0, newSize;

	for (int i = 0; i < strlen(statement); ++i)
	{
		if (statement[i] == ' ')
		{
			++numberOfSpaces;
		}
	}

	newSize = strlen(statement) + numberOfSpaces * 2;
	statement[newSize] = '\0';

	int posOriginal, finalPos;

	for (finalPos = newSize - 1, posOriginal = strlen(statement) - 1; finalPos >= 0; --finalPos, --posOriginal)
	{
		if (statement[posOriginal] != ' ')
		{
			statement[finalPos] = statement[posOriginal];
		}
		else
		{
			statement[finalPos]   = '0';
			statement[--finalPos] = '2';
			statement[--finalPos] = '%';
		}
	}

	std::cout << statement;

	return 0;
}

