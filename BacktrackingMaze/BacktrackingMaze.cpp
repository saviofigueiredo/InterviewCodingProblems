#include <iostream>
#include <tuple>
#include <list>

#define BoardSize 6
#define Player 'X'
#define Wall '#'
#define Space '.'
#define Door 'G'

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

std::list<std::pair<int, int>> getNextPossiblePositions(std::pair<int, int> playerPosition, char board[BoardSize][BoardSize])
{
	std::list<std::pair<int, int>> playerNextPositions;
	std::list<std::pair<int, int>> playerPossibleSteps;

	playerPossibleSteps.push_back(std::make_pair(playerPosition.first - 1, playerPosition.second));
	playerPossibleSteps.push_back(std::make_pair(playerPosition.first + 1, playerPosition.second));
	playerPossibleSteps.push_back(std::make_pair(playerPosition.first, playerPosition.second + 1));
	playerPossibleSteps.push_back(std::make_pair(playerPosition.first, playerPosition.second - 1));

	for (auto playerPossibleStep = playerPossibleSteps.begin(); playerPossibleStep != playerPossibleSteps.end(); ++playerPossibleStep)
	{
		auto step = *playerPossibleStep;
		if (step.first >= 0 && step.first < BoardSize && step.second >= 0 && step.second < BoardSize && (board[step.first][step.second] == Space || board[step.first][step.second] == Door))
		{
			playerNextPositions.push_back(step);
		}
	}

	return playerNextPositions;
}

bool maze(std::pair<int, int> playerPosition, char board[BoardSize][BoardSize])
{
	std::list<std::pair<int, int>> playerNextPositions = getNextPossiblePositions(playerPosition, board);

	for (auto it = playerNextPositions.begin(); it != playerNextPositions.end(); ++it)
	{
		std::pair<int, int> nextPosition = (*it);

		if (board[nextPosition.first][nextPosition.second] == Door)
		{
			return true;
		}

		board[nextPosition.first][nextPosition.second] = Player;

		if (maze(nextPosition, board) == true)
		{
			return true;
		}

		board[nextPosition.first][nextPosition.second] = Space;
	}

	return false;
}

int main(int argc, char* argv[])
{   
	char board[BoardSize][BoardSize] = { { Player, Wall,  Wall,  Wall,  Wall,  Wall },
										 { Space,  Space, Space, Space, Space, Wall },
										 { Wall,   Space, Wall,  Wall,  Wall,  Wall },
										 { Wall,   Space, Wall,  Wall,  Wall,  Wall },
										 { Space,  Space, Space, Wall,  Space, Door },
										 { Wall,   Wall,  Space, Space, Space, Wall } };

	print(board);

	std::pair<int, int> playerPosition = std::make_pair(0, 0);

	maze(playerPosition, board);

	print(board);
}