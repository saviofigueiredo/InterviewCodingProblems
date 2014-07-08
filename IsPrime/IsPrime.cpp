#include <iostream>

bool isPrime(int n)
{
	if (n == 0)
	{
		return false;
	}

	n = abs(n);

	for (auto i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	std::cout << "100 isPrime " << isPrime(100) << std::endl; 
	std::cout << "17 isPrime " << isPrime(17) << std::endl;
	std::cout << "1007 isPrime " << isPrime(1007) << std::endl;
}