#include <iostream>
#include <stack>
#include <tuple>
#include <list>

#define BoardSize 7

#define Peg 'X'
#define Hole '0'
#define Lock '*'

typedef enum Direction
{
	up,
	down,
	left,
	right
}Direction;

void print(char board[BoardSize][BoardSize])
{
	std::cout << std::endl << std::endl;

	for (auto i = 0; i < BoardSize; ++i)
	{
		for (auto j = 0; j < BoardSize; ++j)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

std::list<Direction> getMoves()
{
	std::list<Direction> moves;
	moves.push_back(Direction::right);
	moves.push_back(Direction::left);
	moves.push_back(Direction::up);
	moves.push_back(Direction::down);

	return moves;
}

bool canMakeMove(int x, int y, char board[BoardSize][BoardSize], Direction direction)
{
	if (board[x][y] != Peg)
	{
		return false;
	}

	if (direction == Direction::up && x < 2
		|| direction == Direction::down && x >= BoardSize - 2
		|| direction == Direction::left && y < 2
		|| direction == Direction::right && y >= BoardSize - 2)
	{
		return false;
	}

	if (direction == Direction::up)
	{
		if (board[x - 1][y] != Peg || board[x - 2][y] != Hole)
		{
			return false;
		}
	}
	if (direction == Direction::down)
	{
		if (board[x + 1][y] != Peg || board[x + 2][y] != Hole)
		{
			return false;
		}
	}

	if (direction == Direction::left)
	{
		if (board[x][y - 1] != Peg || board[x][y - 2] != Hole)
		{
			return false;
		}
	}
	if (direction == Direction::right)
	{
		if (board[x][y + 1] != Peg || board[x][y + 2] != Hole)
		{
			return false;
		}
	}

	return true;
}

void makeMove(int x, int y, char board[BoardSize][BoardSize], Direction direction)
{
	board[x][y] = Hole;

	if (direction == Direction::up)
	{
		board[x - 1][y] = Hole;
		board[x - 2][y] = Peg;
	}
	if (direction == Direction::down)
	{
		board[x + 1][y] = Hole;
		board[x + 2][y] = Peg;
	}
	if (direction == Direction::left)
	{
		board[x][y-1] = Hole;
		board[x][y-2] = Peg;
	}
	if (direction == Direction::right)
	{
		board[x][y+1] = Hole;
		board[x][y+2] = Peg;
	}
}

void makeMoveBack(int x, int y, char board[BoardSize][BoardSize], Direction direction)
{
	board[x][y] = Peg;

	if (direction == Direction::up)
	{
		board[x - 1][y] = Peg;
		board[x - 2][y] = Hole;
	}
	if (direction == Direction::down)
	{
		board[x + 1][y] = Peg;
		board[x + 2][y] = Hole;
	}
	if (direction == Direction::left)
	{
		board[x][y - 1] = Peg;
		board[x][y - 2] = Hole;
	}
	if (direction == Direction::right)
	{
		board[x][y + 1] = Peg;
		board[x][y + 2] = Hole;
	}
}

bool pegSolitaire(int moveNumber, char board[BoardSize][BoardSize])
{
	if (moveNumber > 31)
	{
		return true;
	}

	auto moves = getMoves();

	for (auto i = 0; i < BoardSize; ++i)
	{
		for (auto j = 0; j < BoardSize; ++j)
		{
			for (auto move = moves.begin(); move != moves.end(); ++move)
			{
				if (canMakeMove(i, j, board, *move))
				{
					makeMove(i, j, board, *move);

					if (pegSolitaire(moveNumber + 1, board))
					{
						return true;
					}
					print(board);
					makeMoveBack(i, j, board, *move);
				}
			}
		}
	}

	return false;
}

int main(int argc, char* argv[])
{
	char board[BoardSize][BoardSize] = 
	{ 
		{Lock, Lock, Peg, Peg, Peg,  Lock, Lock },
		{Lock, Lock, Peg, Peg, Peg,  Lock, Lock },
		{Peg,  Peg,  Peg, Peg,  Peg, Peg,  Peg },
		{Peg,  Peg,  Peg, Hole, Peg, Peg,  Peg },
		{Peg,  Peg,  Peg, Peg,  Peg, Peg,  Peg },
		{Lock, Lock, Peg, Peg, Peg,  Lock, Lock },
		{Lock, Lock, Peg, Peg, Peg,  Lock, Lock },
	};

	print(board);

	pegSolitaire(1, board);

	print(board);
}