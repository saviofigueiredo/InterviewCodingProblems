#include <string>
#include <iostream>

int findIndex(std::string s, int number)
{
	int r = 10;
	int count = 0;

	int n = number;
	while (n > 0)
	{
		n /= 10;

		count++;
	}

	double pos = 0;

	pos += (number - pow(10, count - 1)) * count;
	--count;

	while (count > 0)
	{
		pos += pow(10, count - 1) * 9;
		--count;
	}

	return int(pos);
}

int main(int argc, char* argv[])
{
	std::string s;

	for (int i = 0; i < 10000; ++i)
	{
		s += std::to_string(i);
	}

	std::cout << "Index of 5 is " << findIndex(s, 5) << std::endl;
	std::cout << "Index of 20 is " << findIndex(s, 20) << std::endl;
	std::cout << "Index of 100 is " << findIndex(s, 100) << std::endl;
	std::cout << "Index of 335 is " << findIndex(s, 335) << std::endl;
}