#include <iostream>

int maximumIncreasingSubsequence(int* v, int length)
{
	int maxLength = 1, bestEnd = 0;
	int *dp = (int*) malloc(length*sizeof(int));
	int *prev = (int*)malloc(length*sizeof(int));

	dp[0] = 1;

	for (int i = 0; i < length; ++i)
	{
		prev[i] = -1;
	}

	for (int i = 1; i < length; i++)
	{
		dp[i] = 1;

		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j] + 1 > dp[i] && v[j] < v[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
		
		if (dp[i] > maxLength)
		{
			bestEnd = i;
			maxLength = dp[i];
		}
	}

	for (int i = bestEnd; i != -1; i = prev[i])
	{
		std::cout << v[i] << std::endl;
	}

	return maxLength;
}

int main(int argc, char* argv[])
{
	int v[] = { 2, 4, 3, 5, 1, 7, 6, 9, 8 };

	std::cout << maximumIncreasingSubsequence(v, sizeof(v)/sizeof(int));
}