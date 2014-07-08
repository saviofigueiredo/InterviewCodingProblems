// CheckTwoStringsHaveSameCharacterCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

bool checkSameCharacterCount(char s1[], int s1Length, char s2[], int s2Length)
{
	int count[256];

	memset(count, 0, 256 * sizeof(int));

	if (s1Length != s2Length)
	{
		std::cout << "The strings do not have the same character count";
		return false;
	}

	for (int i = 0; i < s1Length; ++i)
	{
		++count[s1[i]];
		--count[s2[i]];
	}

	for (int i = 0; i < 256; ++i)
	{
		if (count[i] != 0)
		{
			std::cout << "The strings do not have the same character count";
			return false;
		}
	}

	std::cout << "Both strings have the same character count" << std::endl;
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s1[] = "ab ab ab ab de de de de";
	char s2[] = "bd bd bd bd ea ea ea ea";

	checkSameCharacterCount(s1, sizeof(s1)/sizeof(char), s2, sizeof(s2)/sizeof(char));

	char s3[] = "a";
	char s4[] = "";

	checkSameCharacterCount(s3, sizeof(s3)/sizeof(char), s4, sizeof(s4)/sizeof(char));

	return 0;
}

