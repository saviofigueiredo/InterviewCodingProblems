// FindCharactersJustAppearOnceArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

char* findCharactersJustAppearOnce(char _array[], int _length)
{
	char characterCount[512];
	char* response;
	int count = 0, j;

	memset(characterCount, 0, 512);

	for (int i = 0; i < _length; ++i)
	{
		++characterCount[_array[i]];

		if (characterCount[_array[i]] == 1)
		{
			++count;
		}
		else if (characterCount[_array[i]] == 2)
		{
			--count;
		}
	}

	response = (char*) malloc((count + 1)*sizeof(char));

	j = 0;
	for (int i = 0; i < _length; ++i)
	{
		if (characterCount[_array[i]] == 1)
		{
			response[j] = _array[i];
			++j;
		}
	}

	response[j] = '\0';

	return response;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char array[] = "This is my test array. Which characters just appear once?";

	char* response = findCharactersJustAppearOnce(array, sizeof(array)/sizeof(char));
	
	std::cout << response;

	return 0;
}

