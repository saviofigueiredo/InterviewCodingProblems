#include <iostream>

int numbers[] = { -2, 4, 3, 1, 20, 100, 200, 3000, 5, 70, 80 };

void alternateTroughSorting()
{
	int t;

	for (int i = 0; i < sizeof(numbers) / sizeof(int) - 1; ++i)
	{
		for (int j = i + 1; j < sizeof(numbers) / sizeof(int); ++j)
		{
			if (numbers[j] < numbers[i])
			{
				t = numbers[j];
				numbers[j] = numbers[i];
				numbers[i] = t;
			}
		}
	}

	for (int i = 1; i < sizeof(numbers) / sizeof(int) - 1; i += 2)
	{
		t = numbers[i];
		numbers[i] = numbers[i + 1];
		numbers[i + 1] = t;
	}

	for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i)
	{
		std::cout << numbers[i] << std::endl;
	}
}

void arrangeList()
{
	int t;

	for (int i = 1; i<sizeof(numbers) / sizeof(int); i++)
	{
		if (i % 2 && numbers[i] < numbers[i - 1])
		{
			t = numbers[i];
			numbers[i] = numbers[i - 1];
			numbers[i - 1] = t;
		}
		if (i % 2 == 0 && numbers[i] > numbers[i - 1])
		{
			t = numbers[i];
			numbers[i] = numbers[i - 1];
			numbers[i - 1] = t;
		}
	}

	for (int i = 0; i < sizeof(numbers) / sizeof(int); ++i)
	{
		std::cout << numbers[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{
	// alternateTroughSorting();
	arrangeList();

	return 0;
}
