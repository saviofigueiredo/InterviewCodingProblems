#include <iostream>

long long binomialCoeficient(int n, int k)
{
	long long **m = (long long**)malloc((n + 1)*sizeof(long long));

	for (auto i = 0; i <= n; ++i)
	{
		m[i] = (long long*) malloc((n + 1)*sizeof(long long));

		m[i][i] = 1;
		m[i][0] = 1;
		m[i][1] = i;
	}

	for (auto i = 0; i <= n; ++i)
	{
		for (auto j = 1; j < i; ++j)
		{
			m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
		}
	}

	return m[n][k];
}

int main()
{
	std::cout << binomialCoeficient(5, 3);
}