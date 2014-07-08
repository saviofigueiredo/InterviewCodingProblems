#include <iostream>

const unsigned PrimeBase = 257;
const unsigned PrimeMod = 1000000007;

unsigned hash(char* s)
{
	long long hash = 0;

	for (int i = 0; s[i] != '\0'; ++i)
	{
		hash = (hash*PrimeBase + s[i]) % PrimeMod;
	}

	return hash;
}

int rabinKarp(char* pattern, char* s)
{
	long long hashPattern = hash(pattern);

	long long hashS = 0;

	long long power = 1;

	int patternLength = 0;

	for (int i = 0; pattern[i] != '\0'; ++i)
	{
		power = (power * PrimeBase) % PrimeMod;
		++patternLength;
	}

	for (int i = 0; s[i] != '\0'; ++i)
	{
		hashS = (hashS * PrimeBase + s[i]) % PrimeMod;

		if (i >= patternLength)
		{
			hashS -= power * s[i - patternLength] % PrimeMod;

			if (hashS < 0)
			{
				hashS += PrimeMod;
			}
		}

		if (i >= patternLength && hashS == hashPattern)
		{
			return i - (patternLength - 1);
		}
	}

	return -1;
}

int main(int argc, char* argv[])
{
	char s[] = "rolling hash implementation";
	char pattern[] = "hash";

	std::cout << rabinKarp(pattern, s);
}