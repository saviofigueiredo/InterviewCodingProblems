/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.  
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/
#include <iostream>
#include <algorithm>

int knapsackRecursive(int maxWeight, int numberItems, int weights[], int values[])
{
	if (numberItems == 0 || maxWeight == 0)
	{
		return 0;
	}

	if (weights[numberItems - 1] > maxWeight)
	{
		return knapsackRecursive(maxWeight, numberItems - 1, weights, values);
	}

	return std::max(
		values[numberItems - 1] + knapsackRecursive(maxWeight - weights[numberItems - 1], numberItems - 1, weights, values),
		knapsackRecursive(maxWeight, numberItems - 1, weights, values));
}

int knapsackDynamicProgramming(int maxWeight, int numberItems, int weights[], int values[])
{
	int **k;
	k = (int**)malloc((numberItems + 1)*sizeof(int));
	for (auto i = 0; i <= numberItems; ++i)
	{
		k[i] = (int*)malloc((maxWeight + 1)*sizeof(int));
	}

	for (auto i = 0; i <= numberItems; ++i)
	{
		for (auto j = 0; j <= maxWeight; ++j)
		{
			if (i == 0 || j == 0)
			{
				k[i][j] = 0;
			}
		}
	}

	for (auto i = 1; i <= numberItems; ++i)
	{
		for (auto j = 1; j <= maxWeight; ++j)
		{
			if (weights[i - 1] <= j)
			{
				k[i][j] = std::max(values[i - 1] + k[i - 1][j - weights[i - 1]], 
								   k[i - 1][j]);
			}
			else
			{
				k[i][j] = k[i - 1][j];
			}
		}
	}

	for (auto i = 0; i <= numberItems; ++i)
	{
		for (auto j = 0; j <= maxWeight; ++j)
		{
			std::cout << "Items = " << i << " Max Weight = " << j << " Max value = " << k[i][j] << std::endl;
		}
	}

	return k[numberItems][maxWeight];
}

int main(int argc, char* argv[])
{
	int val[] = { 3, 5, 6 };
	
	int wt[] = { 1, 2, 3 };
	
	int  W = 5;
	
	std::cout << knapsackRecursive(W, 3, wt, val) << std::endl;
	std::cout << knapsackDynamicProgramming(W, 3, wt, val) << std::endl;
}