#include <iostream>
#include <list>
#include <tuple>

#define BoardSize 5
#define Empty 0

void print(int** board)
{
	std::cout << std::endl;

	for (auto i = 0; i < BoardSize; ++i)
	{
		for (auto j = 0; j < BoardSize; ++j)
		{
			std::cout << board[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

std::list<std::pair<int, int>> getValidMoves(std::pair<int, int> currentPos, int** board)
{
	std::list<std::pair<int, int>> validMoves;

	int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	
	for (auto i = 0; i < 8; ++i)
	{
		if (currentPos.first + xMove[i] >= 0 && currentPos.first + xMove[i] < BoardSize 
		 && currentPos.second + yMove[i] >= 0 && currentPos.second + yMove[i] < BoardSize 
		 &&	board[currentPos.first + xMove[i]][currentPos.second + yMove[i]] == Empty)
		{
			validMoves.push_back(std::make_pair(currentPos.first + xMove[i], currentPos.second + yMove[i]));
		}
	}

	return validMoves;
}

bool knightTour(std::pair<int, int> currentPos, int currentValue, int** board)
{
	if (currentValue > BoardSize*BoardSize)
	{
		return true;
	}

	auto validMoves = getValidMoves(currentPos, board);

	for (auto it = validMoves.begin(); it != validMoves.end(); ++it)
	{
		auto pos = *it;

		board[pos.first][pos.second] = currentValue;

		if (knightTour(pos, currentValue + 1, board))
		{
			return true;
		}

		board[pos.first][pos.second] = Empty;
	}

	return false;
}

int main(int argc, char** argv)
{
	int** board;

	board = (int**)malloc(BoardSize*sizeof(int));

	for (auto i = 0; i < BoardSize; ++i)
	{
		board[i] = (int*)malloc(BoardSize*sizeof(int));
		
		for (auto j = 0; j < BoardSize; ++j)
		{
			board[i][j] = Empty;
		}
	}

	std::pair<int, int> currentPos = std::make_pair(0, 0);
	board[currentPos.first][currentPos.second] = 1;
	print(board);
	knightTour(currentPos, 2, board);
	print(board);
}