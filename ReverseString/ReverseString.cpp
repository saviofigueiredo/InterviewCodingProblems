// ReverseString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

void reverseString(char s[], int length)
{
	for (int i = 0; i < length/2; ++i)
	{
		char temp = s[length - i - 1];
		s[length - i - 1] = s[i];
		s[i] = temp;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char stringToBeReverted[] = "This string should be reversed!";

	reverseString(stringToBeReverted, sizeof(stringToBeReverted)/sizeof(char));

	for (int i = 0; i < sizeof(stringToBeReverted)/sizeof(char); ++i)
	{
		std::cout << stringToBeReverted[i];
	}

	return 0;
}

