/*
Given a robot that is inside a maze, your job is to write a program that will help this robot 
to leave the maze.

    1  2  3  4  5  6  7  8 
   ________________________
1 |    X        X  X     X | 
2 |    X        X  X     X |
3   R> X        X  X       |
4 |    X        X  X       |
5 |             X  X       
6 |                        |
7 |    X  X              X |
8 |    X  X              X |
  --------------------------

Commands:
MOVE			// move 1 step forward
TURN_LEFT		// 90degree turn left
ITERATE n TIMEs	// n is int, loop n times
ITERATE FOREVER
IF(Condition) THEN
ELSE

Conditions :
IS_WALL_IN_FRONT
IS_WALL_ON_LEFT
!			// Not

{}

Solution
This left hand on wall algorithm can be simplified into these simple conditions:
- If you can turn left then go ahead and turn left,
- else if you can continue driving straight then drive straight,
- else if you can turn right then turn right.
- If you are at a dead end then turn around.
*/
#include <iostream>
#include <list>

const unsigned char Wall = 219;
const unsigned char Robot = 1;
const unsigned char Empty = 177;
const unsigned char Door = 178;

enum Direction
{
	up,
	down,
	right,
	left
};

typedef struct Maze
{
	char** board;

	int BoardSize;

	int robotLine;
	int robotColumn;
	
	int doorLine;
	int doorColumn;
	
	Direction robotDirection;

	static Maze* newMaze()
	{
		auto newMaze = (Maze*)malloc(sizeof(Maze));
		
		newMaze->BoardSize = 8;
		newMaze->doorColumn = 7;
		newMaze->doorLine = 4;

		newMaze->board = (char**)malloc(newMaze->BoardSize*sizeof(char));
		for (auto i = 0; i < newMaze->BoardSize; ++i)
		{
			newMaze->board[i] = (char*)malloc(newMaze->BoardSize*sizeof(char));

			for (auto j = 0; j < newMaze->BoardSize; ++j)
			{
				newMaze->board[i][j] = Empty;
			}
		}

		newMaze->robotLine = 2;
		newMaze->robotColumn = 0;
		newMaze->robotDirection = right;
		newMaze->board[newMaze->robotLine][newMaze->robotColumn] = Robot;

		newMaze->board[0][2] = newMaze->board[1][2] = newMaze->board[2][2] = newMaze->board[3][2] = Wall;
		newMaze->board[6][1] = newMaze->board[7][1] = Wall;
		newMaze->board[6][2] = newMaze->board[7][2] = Wall;
		newMaze->board[0][4] = newMaze->board[1][4] = newMaze->board[2][4] = newMaze->board[3][4] = newMaze->board[4][4] = Wall;
		newMaze->board[0][5] = newMaze->board[1][5] = newMaze->board[2][5] = newMaze->board[3][5] = newMaze->board[4][5] = Wall;
		newMaze->board[0][7] = newMaze->board[1][7] = newMaze->board[6][7] = newMaze->board[7][7] = Wall;
		newMaze->board[newMaze->doorLine][newMaze->doorColumn] = Door;

		return newMaze;
	}

	bool isWallInFront()
	{
		if (robotDirection == right)
		{
			return robotColumn + 1 == BoardSize || board[robotLine][robotColumn + 1] == Wall;
		}
		else if (robotDirection == left)
		{
			return robotColumn == 0 || board[robotLine][robotColumn - 1] == Wall;
		}
		else if (robotDirection == up)
		{
			return robotLine == 0 || board[robotLine - 1][robotColumn] == Wall;
		}
		else if (robotDirection == down)
		{
			return robotLine + 1 == BoardSize || board[robotLine + 1][robotColumn] == Wall;
		}

		return false;
	}

	bool isWallOnLeft()
	{
		turnLeft();
		auto hasWall = isWallInFront();
		turnLeft();
		turnLeft();
		turnLeft();

		return hasWall;
	}

	void turnLeft()
	{
		if (robotDirection == right)
		{
			robotDirection = up;
		}
		else if (robotDirection == left)
		{
			robotDirection = down;
		}
		else if (robotDirection == up)
		{
			robotDirection = left;
		}
		else if (robotDirection == down)
		{
			robotDirection = right;
		}
	}

	void move()
	{
		if (isWallInFront())
		{
			return;
		}

		int oldColumn = robotColumn;
		int oldLine = robotLine;

		if (robotDirection == right)
		{
			robotColumn++;
		}
		else if (robotDirection == left)
		{
			robotColumn--;
		}
		else if (robotDirection == up)
		{
			robotLine--;
		}
		else if (robotDirection == down)
		{
			robotLine++;
		}

		board[oldLine][oldColumn] = Empty;
		board[robotLine][robotColumn] = Robot;
	}

	bool isAtDoor()
	{
		return robotLine == doorLine && robotColumn == doorColumn;
	}

	void solve()
	{
		print();
		
		while (isAtDoor() == false)
		{
			if (isWallOnLeft() == false)
			{
				turnLeft();
				move();
			}
			else
			{
				if (isWallInFront() == false)
				{
					move();
				}
				else
				{
					turnLeft();
					turnLeft();
					turnLeft();
				}
			}

			print();
		}
	}

	void print()
	{
		unsigned const char Right = 175;
		unsigned const char Left = 174;
		unsigned const char Up = 30;
		unsigned const char Down = 31;

		if (robotDirection == up) board[robotLine][robotColumn] = Up;
		if (robotDirection == down) board[robotLine][robotColumn] = Down;
		if (robotDirection == right) board[robotLine][robotColumn] = Right;
		if (robotDirection == left) board[robotLine][robotColumn] = Left;

		std::cout << std::endl << " ________" << std::endl;
		for (auto i = 0; i < BoardSize; ++i)
		{
			std::cout << "|";
			for (auto j = 0; j < BoardSize; ++j)
			{
				std::cout << board[i][j];
			}
			std::cout << "|" << std::endl;
		}

		std::cout << " --------" << std::endl << std::endl;
	}

}Maze;

int main(int argc, char* argv[])
{
	auto maze = Maze::newMaze();

	maze->solve();

	return EXIT_SUCCESS;
}