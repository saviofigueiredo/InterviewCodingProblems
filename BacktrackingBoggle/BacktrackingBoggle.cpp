/*
Write a program to implement Boggle Game.

You are given a 4x4 matrix of letters and a dictionary, find all the valid words in the matrix. Following are the conditions
1. If a letter is used, it should not be used again in the same word search
2. The word path can be of any direction
3. There has to be a path of the letters forming the word( in other words all the letters in the word must have to adjacent to one another)


Example:

D A T H
C G O A
S A T L
B E D G

Some of the Valid words are:
DATA, HALO, HALT, SAG, BEAT, TOTAL, GLOT, DAG

Not valid words:
DAGCD ( D cannot be used again)
DOG ( There is no path between letters)
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>
#include <sstream>

typedef struct Node
{
	Node* next;
	char word[15];

	static Node* newNode()
	{
		auto node = (Node*)malloc(sizeof(Node));
		node->next = nullptr;

		return node;
	}
} Node;

typedef struct Queue
{
	Node* head;
	Node* tail;

	static Queue* newQueue()
	{
		auto q = (Queue*)malloc(sizeof(Queue));
		q->head = nullptr;
		q->tail = nullptr;
	
		return q;
	}

	Node* add(char word[])
	{
		auto node = Node::newNode();

		for (auto i = 0; word[i] != '\0'; ++i)
		{
			node->word[i] = word[i];
			node->word[i + 1] = '\0';
		}

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}

		return node;
	}
}Queue;

typedef struct Dictionary
{
	Queue* queue;
	std::unordered_map<char, Node*> hashTable;

	Dictionary()
	{
		queue = Queue::newQueue();
	}

	void read(std::string filePath)
	{
		std::fstream fs;
		char word[15];

		fs.open(filePath, std::fstream::in | std::fstream::out | std::fstream::app);

		if (fs.is_open())
		{
			while (fs.eof() == false)
			{
				auto node = Node::newNode();

				fs.getline(word, 15);

				add(word);
			}
		}
	}
	
	void add(char word[])
	{
		auto node = queue->add(word);

		char c = node->word[0];

		if (hashTable.find(c) == hashTable.end())
		{
			hashTable.insert(std::make_pair(c, node));
		}
	}

	bool contains(std::string word)
	{
		auto firstChar = word[0];

		if (hashTable.find(firstChar) != hashTable.end())
		{
			auto currentNode = hashTable[firstChar];

			while (currentNode && currentNode->word[0] == firstChar && strcmp(currentNode->word, word.c_str()) <= 0)
			{
				if (strcmp(currentNode->word, word.c_str()) == 0)
				{
					return true;
				}

				currentNode = currentNode->next;
			}
		}

		return false;
	}
}Dictionary;

typedef struct Boggle
{
	static std::list<std::pair<int, int>> getNextMoves(int currentLine, int currentColumn, std::list<std::pair<int, int>>& visitedCells)
	{
		int c[8] = { -1, 0, 1, -1, 1, -1,  0,  1 };
		int l[8] = {  1, 1, 1,  0, 0, -1, -1, -1 };

		std::list<std::pair<int, int>> nextMoves;

		for (auto i = 0; i < 8; ++i)
		{
			auto newColumn = c[i] + currentColumn;
			auto newLine = l[i] + currentLine;
		
			if (newLine >= 0 && newLine < 4 && newColumn >= 0 && newColumn < 4 && std::find(visitedCells.begin(), visitedCells.end(), std::make_pair(newLine, newColumn)) == visitedCells.end())
			{
				nextMoves.push_back(std::make_pair(newLine, newColumn));
			}
		}

		return nextMoves;
	}

	static void boggle(char board[4][4], int currentLine, int currentColumn, Dictionary* dictionary, std::list<std::pair<int, int>> visitedCells, std::list<std::string>& solutions, std::string currentWord)
	{
		auto nextMoves = getNextMoves(currentLine, currentColumn, visitedCells);

		for (auto move = nextMoves.begin(); move != nextMoves.end(); ++move)
		{
			auto newLine = (*move).first;
			auto newColumn = (*move).second;

			visitedCells.push_back(std::make_pair(newLine, newColumn));

			currentWord.push_back(board[newLine][newColumn]);

			if (dictionary->contains(currentWord))
			{
				solutions.push_back(currentWord);
			}

			boggle(board, newLine, newColumn, dictionary, visitedCells, solutions, currentWord);
		}
	}

	static std::list<std::string> boggle(char board[4][4], Dictionary* dictionary)
	{
		std::list<std::string> solutions;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				std::list<std::pair<int, int>> visitedCells;
				visitedCells.push_back(std::make_pair(i, j));
				std::string newWord;
				newWord.push_back(board[i][j]);

				if (dictionary->contains(newWord))
				{
					solutions.push_back(newWord);
				}

				boggle(board, i, j, dictionary, visitedCells, solutions, newWord);
			}
		}

		return solutions;
	}
}Boggle;

int main(int argc, char* argv[])
{
	Dictionary* dictionary = new Dictionary();

	dictionary->read("dictionary.txt");
	
	char board[4][4] = { { 'm', 'a', 'n', 'i' },
						 { 'e', 'e', 't', 'l' },
						 { 'd', 's', 'p', 'e' },
						 { 'i', 'r', 'e', 'd' }};

	auto solutions = Boggle::boggle(board, dictionary);

	for (auto it = solutions.begin(); it != solutions.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
}