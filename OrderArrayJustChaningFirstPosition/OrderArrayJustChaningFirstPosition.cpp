// OrderArrayJustChaningFirstPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void change(int v[], int pos)
{
	v[0] = v[0] + v[pos];

	v[pos] = v[0] - v[pos];

	v[0] = v[0] - v[pos];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int v[] = {4, 2, 1, 10, 7, 8, 3, 5};

	for (int i = sizeof(v)/sizeof(int) - 1; i >= 0; --i)
	{
		int indexElementToChange = i;

		for (int j = i - 1; j >= 0; --j)
		{
			if (v[j] > v[indexElementToChange])
			{
				indexElementToChange = j;
			}
		}

		if (indexElementToChange != i)
		{
			if (indexElementToChange != 0)
			{
				change(v, indexElementToChange);
			}

			change(v, i);
		}
	}

	for (int i = 0; i < sizeof(v)/sizeof(int); ++i)
	{
		std::cout << v[i] << " ";
	}

	return 0;
}

