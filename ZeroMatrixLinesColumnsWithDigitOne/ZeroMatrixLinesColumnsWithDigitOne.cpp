#include <iostream>

void zeroMatrixLinesColumnsWithDigitOne(int matrix[3][3])
{
	int linesToZero[3];
	int columnsToZero[3];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (matrix[i][j] == 1)
			{
				linesToZero[i] = 1;
				columnsToZero[j] = 1;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (linesToZero[i] == 1 || columnsToZero[j] == 1)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void printMatrix(int matrix[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	int matrix[3][3] = { { 2, 3, 4 }, { 3, 1, 1 }, { 4, 1, 9 } };

	printMatrix(matrix);

	zeroMatrixLinesColumnsWithDigitOne(matrix);

	printMatrix(matrix);

	return 0;
}