// FindAngleBetweenClockHands.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	int minutes = 30, hours = 1;

	float angleMinutes = float((360/60)*minutes);

	float angleHours = float((360/12)*hours + minutes/2);

	float answer = angleHours - angleMinutes;

	if (answer < 0)
	{
		answer *= -1;
	}

	if (answer > 180)
	{
		answer = 360 - answer;
	}

	std::cout << answer;

	return 0;
}

