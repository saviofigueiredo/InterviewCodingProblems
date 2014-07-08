// printBinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void printBinary(int number)
{
	if (number < 2)
	{
		std::cout << number;
	}
	else
	{
		printBinary(number / 2);
		std::cout << number % 2;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	printBinary(10);

	return 0;
}

