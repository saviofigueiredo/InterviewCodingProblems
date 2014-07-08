#include <iostream>

int smallestNumberAllDigitsMultipliedEqualNumber(int n)
{
	int v[100];
	int pos = 0;

	if (n < 10)
	{
		return n + 10;
	}

	for (auto i = 9; i > 1; --i)
	{
		while (n % i == 0)
		{
			n /= i;
			v[pos++] = i;
		}
	}

	if (pos == 0)
	{
		return pos;
	}

	int number = 0;

	for (auto i = 0; i < pos; ++i)
	{
		number += v[i] * pow(10, i);
	}

	return number;
}

int main(int argc, char* argv[])
{
	std::cout << smallestNumberAllDigitsMultipliedEqualNumber(36) << std::endl;
	std::cout << smallestNumberAllDigitsMultipliedEqualNumber(100) << std::endl;
	std::cout << smallestNumberAllDigitsMultipliedEqualNumber(1) << std::endl;
}