#include <iostream>
#include <string>
#include <algorithm>

int min(unsigned int a, unsigned int b, unsigned int c)
{
	return std::min(std::min(a, b), c);
}

void print(int**m, size_t r, size_t c)
{
	for (size_t i = 0; i < r; ++i)
	{
		for (size_t j = 0; j < c; ++j)
		{
			if (m[i][j] < 10)
			{
				std::cout << '0';
			}

			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int stringDistance(std::string s1, std::string s2)
{
	int **m = (int**)malloc((s1.length() + 1) * sizeof(int));

	for (size_t i = 0; i <= s1.length(); ++i)
	{
		m[i] = (int*)malloc((s2.length() + 1) * sizeof(int));
		m[i][0] = i;
	}

	for (size_t i = 0; i <= s2.length(); ++i)
	{
		m[0][i] = i;
	}

	for (size_t i = 1; i <= s1.length(); ++i)
	{
		for (size_t j = 1; j <= s2.length(); ++j)
		{
			auto cost = 0;
			
			if (s1[i - 1] != s2[j - 1])
			{
				cost = 1;
			}

			m[i][j] = min(m[i - 1][j - 1] + cost,
						  m[i - 1][j] + 1,
						  m[i][j - 1] + 1);
		}
	}

	print(m, s1.length() + 1, s2.length() + 1);

	std::cout << "The distance between (" << s1 << ") and (" << s2 << ") is " << m[s1.length()][s2.length()] << std::endl;

	return m[s1.length()][s2.length()];
}

int stringDistanceRecursion(std::string s1, std::string s2)
{
	if (s1.length() == 0 && s2.length() == 0)
	{
		return 0;
	}
	else if (s1.length() == 0)
	{
		return s2.length();
	}
	else if (s2.length() == 0)
	{
		return s1.length();
	}

	int cost = 0;

	if (s1[0] != s2[0])
	{
		cost = 1;
	}

	std::string s1WithoutFirstChar = s1.substr(1, s1.length() - 1);
	std::string s2WithoutFirstChar = s2.substr(1, s2.length() - 1);
	
	int distanceS1S2 = min(stringDistanceRecursion(s1WithoutFirstChar, s2WithoutFirstChar) + cost,
						   stringDistanceRecursion(s1WithoutFirstChar, s2) + 1,
						   stringDistanceRecursion(s1, s2WithoutFirstChar) + 1);
	std::cout << "The distance between (" << s1 << ") and (" << s2 << ") is " << distanceS1S2 << std::endl;
	
	return distanceS1S2;
}

int main()
{
	stringDistance("appropriate meaning", "approximate matching");
}