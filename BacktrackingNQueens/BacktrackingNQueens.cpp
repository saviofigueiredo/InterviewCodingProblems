#include <iostream>
#include <string>
#include <math.h>

#define Blank char(2)
#define Queen char(3)

int count = 0;

void print(int* queens, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (queens[i] == j)
			{
				std::cout << Queen << " ";
			}
			else
			{
				std::cout << Blank << " ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;
}

bool canPlace(int* queens, int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		if (i == row || queens[i] == column)
		{
			return false;
		}

		if (abs(row - i) == abs(column - queens[i]))
		{
			return false;
		}
	}

	return true;
}

void nQueens(int* queens, int size, int row)
{
	if (row == size)
	{
		print(queens, size);
		return;
	}

	for (int column = 0; column < size; ++column)
	{
		if (canPlace(queens, row, column))
		{
			queens[row] = column;
			nQueens(queens, size, row + 1);
		}
	}
}

int main(int argc, char* argv[])
{
	int size = 9;

	int* queens = (int*)malloc(size*sizeof(int));

	nQueens(queens, size, 0);

	return EXIT_SUCCESS;
}