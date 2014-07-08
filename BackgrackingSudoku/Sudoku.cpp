#include <unordered_map>
#include <list>
#include <iostream>

typedef struct Sudoku
{
	int peerLine[9][9][20];
	int peerColumn[9][9][20];

	int board[9][9];

	Sudoku()
	{
		initializeBoard();
		initializePeers();
	}

	void initializeBoard()
	{
		for (auto i = 0; i < 9; ++i)
		{
			for (auto j = 0; j < 9; ++j)
			{
				board[i][j] = 0;
			}
		}

		board[0][0] = 4;
		board[0][6] = 8;
		board[0][8] = 5;
		board[1][1] = 3;
		board[2][3] = 7;
		board[3][1] = 2;
		board[3][7] = 6;
		board[4][4] = 8;
		board[4][6] = 4;
		board[5][4] = 1;
		board[6][3] = 6;
		board[6][5] = 3;
		board[6][7] = 7;
		board[7][0] = 5;
		board[7][3] = 2;
		board[8][0] = 1;
		board[8][2] = 4;
	}

	void initializePeers()
	{
		int peerPos;
		for (auto l = 0; l < 9; ++l)
		{
			for (auto c = 0; c < 9; ++c)
			{
				peerPos = 0;

				for (auto z = 0; z < 9; ++z)
				{
					if (z != l)
					{
						peerLine[l][c][peerPos] = z;
						peerColumn[l][c][peerPos] = c;
						++peerPos;
					}
					if (z != c)
					{
						peerLine[l][c][peerPos] = l;
						peerColumn[l][c][peerPos] = z;
						++peerPos;
					}
				}

				for (auto z = 0; z < 3; ++z)
				{
					for (auto w = 0; w < 3; ++w)
					{
						if (l % 3 != z && c % 3 != w)
						{
							peerLine[l][c][peerPos] = (l/3)*3 + z;
							peerColumn[l][c][peerPos] = (c/3)*3 + w;
							++peerPos;
						}
					}
				}
			}
		}
	}

	void printBoard()
	{
		for (auto i = 0; i < 9; ++i)
		{
			for (auto j = 0; j < 9; ++j)
			{
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
	}

	bool getEmptySquare(int &l, int &c)
	{
		for (auto i = 0; i < 9; ++i)
		{
			for (auto j = 0; j < 9; ++j)
			{
				if (board[i][j] == 0)
				{
					l = i;
					c = j;
					return true;
				}
			}
		}

		return false;
	}

	bool solve()
	{
		int l, c;

		if (getEmptySquare(l, c) == false)
		{
			return true;
		}

		char numbersCount[10];
		memset(numbersCount, 0, 10 * sizeof(char));

		for (int i = 0; i < 20; ++i)
		{
			numbersCount[board[peerLine[l][c][i]][peerColumn[l][c][i]]]++;
		}

		for (auto i = 1; i <= 9; ++i)
		{
			if (numbersCount[i] > 0)
			{
				continue;
			}

			board[l][c] = i;

			if (solve() == true)
			{
				return true;
			}

			board[l][c] = 0;
		}

		return false;
	}
}Sudoku;

int main(int argc, char*)
{
	auto game = new Sudoku();

	game->printBoard();

	game->solve();

	std::cout << std::endl << "SOLUTION" << std::endl;

	game->printBoard();
}